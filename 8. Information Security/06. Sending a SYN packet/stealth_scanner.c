#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h> // 1-2)

// 1-2)
#define IP_OF_YOUR_PC "165.246.222.179"
#define IP_OF_DEST "165.246.38.151"

struct tcp_header
{
	unsigned short source_port;
	unsigned short dest_port;
	unsigned int sequence;
	unsigned int acknowledge;
	unsigned char ns : 1;
	unsigned char reserved_part1 : 3;
	unsigned char data_offset : 4;
	unsigned char fin : 1;
	unsigned char syn : 1;
	unsigned char rst : 1;
	unsigned char psh : 1;
	unsigned char ack : 1;
	unsigned char urg : 1;
	unsigned char ecn : 1;
	unsigned char cwr : 1;
	unsigned short window;
	unsigned short checksum;
	unsigned short urgent_pointer;
};

int main()
{
	pcap_if_t *alldevs = NULL;
	char errbuf[PCAP_ERRBUF_SIZE];

	// find all network adapters
	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		printf("dev find failed\n");
		return -1;
	}
	if (alldevs == NULL)
	{
		printf("no devs found\n");
		return -1;
	}

	// print them
	pcap_if_t *d;
	int i;
	for (d = alldevs, i = 0; d != NULL; d = d->next)
	{
		printf("%d-th dev: %s ", ++i, d->name);

		if (d->description)
			printf(" (%s)\n", d->description);
		else
			printf(" (No description available)\n");
	}

	int inum;
	printf("enter the interface number: ");
	scanf("%d", &inum);
	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++)
		; // jump to the inum-th dev

	// open
	pcap_t *fp;
	if ((fp = pcap_open_live(d->name, // name of the device
							 65536,	  // capture size
							 1,		  // promiscuous mode
							 20,	  // read timeout
							 errbuf)) == NULL)
	{
		printf("pcap open failed\n");
		pcap_freealldevs(alldevs);
		return -1;
	}
	printf("pcap open successful\n");

	struct bpf_program fcode;
	if (pcap_compile(fp,							  // pcap handle
					 &fcode,						  // compiled rule
					 (char *)("host 165.246.38.151"), // 캡처할 ip 지정, port 번호 삭제
													  // filter rule
					 1,								  // optimize
					 NULL) < 0)
	{
		printf("pcap compile failed\n");
		pcap_freealldevs(alldevs);
		return -1;
	} // Now we have filter rule in fcode. Apply it to the interface, fp.

	if (pcap_setfilter(fp, &fcode) < 0)
	{
		printf("pcap setfilter failed\n");
		pcap_freealldevs(alldevs);
		return -1;
	}

	printf("filter setting successful\n");

	pcap_freealldevs(alldevs); // we don't need this anymore
	struct pcap_pkthdr *header;
	const unsigned char *pkt_data;

	int res;
	while ((res = pcap_next_ex(fp, &header, &pkt_data)) >= 0) // 1 if success
	{
		if (res == 0) // 0 if time-out
		{
			continue;
		}

		struct tcp_header *th = (struct tcp_header *)(pkt_data + 14 + 20);
		if (th->ack == 1 && th->syn == 1)
			printf("Source port : %d\tDestincation port : %d\n", // Src와 Dest의 port 번호 출력
				   ntohs(th->source_port), ntohs(th->dest_port));
	}
	return 0;
}
