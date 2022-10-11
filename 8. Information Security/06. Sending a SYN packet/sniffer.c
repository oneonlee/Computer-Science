#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h> // 1-2)

// 1-2)
#define IP_OF_YOUR_PC "165.246.222.179"
#define IP_OF_DEST "165.246.38.151"

struct ether_addr
{
	unsigned char ether_addr_octet[6];
};

struct ether_header
{
	struct ether_addr ether_dhost;
	struct ether_addr ether_shost;
	unsigned short ether_type; // 0x0800 for IP
};

struct ip_header
{
	unsigned char ip_header_len : 4;
	unsigned char ip_version : 4;
	unsigned char ip_tos;
	unsigned short ip_total_length;
	unsigned short ip_id;
	unsigned char ip_frag_offset : 5;
	unsigned char ip_more_fragment : 1;
	unsigned char ip_dont_fragment : 1;
	unsigned char ip_reserved_zero : 1;
	unsigned char ip_frag_offset1;
	unsigned char ip_ttl;
	unsigned char ip_protocol;
	unsigned short ip_checksum;
	unsigned int ip_srcaddr;
	unsigned int ip_destaddr;
};

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

// 1-2)
struct pseudo_header
{
	unsigned int source_address;
	unsigned int dest_address;
	unsigned char placeholder;
	unsigned char protocol;
	unsigned short tcp_length;
};

// 1-2)
unsigned short in_checksum(unsigned short *ptr, int nbytes)
{
	register long sum;
	unsigned short oddbyte;
	register short answer;

	sum = 0;
	while (nbytes > 1)
	{
		sum += *ptr++;
		nbytes -= 2;
	}
	if (nbytes == 1)
	{
		oddbyte = 0;
		*((u_char *)&oddbyte) = *(u_char *)ptr;
		sum += oddbyte;
	}

	sum = (sum >> 16) + (sum & 0xffff);
	sum = sum + (sum >> 16);
	answer = (short)~sum; // use “short” in MacOS instead of “SHORT”

	return (answer);
}

// raw byte stream을 출력하는 함수
void print_raw_packet(const unsigned char *pkt_data, bpf_u_int32 caplen)
{
	printf("\nRaw Byte Stream of the Packet\n");
	printf("New Packet of Size : %d\n", caplen);

	for (int i = 0; i < caplen; i++)
	{
		printf("%02x", pkt_data[i]); // 2자리로 표시하고 빈자리는 0으로 채우기
		if (i % 2 == 1)
		{
			printf(" "); // 2bytes마다 space
		}
		if ((i + 1) % 16 == 0)
		{
			printf("\n"); // 16bytes마다 enter
		}
	}
	printf("\n");
}

// Ethernet Header를 출력하는 함수
void print_ether_header(const unsigned char *pkt_data)
{
	struct ether_header *eh;
	eh = (struct ether_header *)pkt_data;

	printf("\nPrinting Ethernet Header: ");
	printf("\n\tDestination MAC Address: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%02x", eh->ether_dhost.ether_addr_octet[i]);
	}
	printf("\n\tSource MAC Address: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%02x", eh->ether_shost.ether_addr_octet[i]);
	}
	printf("\n\tProtocol Type: %04x\n", ntohs(eh->ether_type));
}

// IP Header를 출력하는 함수
void print_ip_header(const unsigned char *pkt_data)
{
	struct ip_header *ih;
	ih = (struct ip_header *)(pkt_data + 14); // ethernet header(14) 이후부터 시작
	printf("\nPrinting IP Header: \n");

	printf("\tIP Version: %x\n", ih->ip_version);
	printf("\tIP Header Length: %d bytes\n", ih->ip_header_len);
	printf("\tIP Type of Service: %d\n", ih->ip_tos);
	printf("\tIP Total Length: %d\n", ntohs(ih->ip_total_length));

	printf("\tIP Identification: %d\n", ntohs(ih->ip_id));
	printf("\tIP Reserved Zero: %x\n", ih->ip_reserved_zero);
	printf("\tIP Don't Fragment: %x\n", ih->ip_dont_fragment);
	printf("\tIP More Fragment: %x\n", ih->ip_more_fragment);
	printf("\tIP Frag Offset: %02x\n", ih->ip_frag_offset);
	printf("\tIP Frag Offset 1: %02x\n", ih->ip_frag_offset1);

	printf("\tIP TTL: %02x\n", ih->ip_ttl);
	printf("\tIP Protocol: %02x\n", ih->ip_protocol);
	printf("\tIP CheckSum: %04x\n", ntohs(ih->ip_checksum));

	printf("\tSource IP Address: %08x\n", ntohl(ih->ip_srcaddr));
	printf("\tDestination IP Address: %08x\n", ntohl(ih->ip_destaddr));
}

// TCP Header를 출력하는 함수
void print_tcp_header(const unsigned char *pkt_data)
{
	struct tcp_header *th;
	th = (struct tcp_header *)&pkt_data[34];

	printf("\nPrinting TCP Header: ");

	printf("\tSource Port Number: %d\n", ntohs(th->source_port));
	printf("\tDestination Port Number: %d\n", ntohs(th->dest_port));

	printf("\tSequence Number: %d\n", ntohl(th->sequence));
	printf("\tACK Number: %d\n", ntohl(th->acknowledge));

	printf("\tTCP Data Offset: %x\n", th->data_offset);
	printf("\tReserved Part 1: %x\n", th->reserved_part1);
	printf("\tTCP NS: %x\n", th->ns);
	printf("\tFIN: %x\n", th->fin);
	printf("\tSYN: %x\n", th->syn);
	printf("\tRST: %x\n", th->rst);
	printf("\tPSH: %x\n", th->psh);
	printf("\tACK: %x\n", th->ack);
	printf("\tURG: %x\n", th->urg);
	printf("\tECN: %x\n", th->ecn);
	printf("\tCWR: %x\n", th->cwr);
	printf("\tWindow: %d\n", ntohs(th->window));

	printf("\tTCP CheckSum: %04x\n", ntohs(th->checksum));
	printf("\tUrgent Pointer: %04x\n", ntohs(th->urgent_pointer));
}

void print_data(const unsigned char *pkt_data, bpf_u_int32 caplen)
{
	if (caplen > 54) // TCP Header는 54bytes에서 끝나고, 그 뒤로는 TCP Option과 data가 온다.
	{
		// if (strstr(pkt_data, "61747461636b") != NULL) // pkt_data에 "attack" strin이 포함되었는지 확인
		// {											  // string "attack"을 16진수 아스키 코드로 변환하면 `61 74 74 61 63 6b`이다.
		// 	printf("ATTACK DETECTED!!!\n");
		// }
		printf("\nPrinting data of packet : \n");
		for (int i = 54; i < caplen; i++)
		{
			printf("%02x", pkt_data[i]); // 2자리로 표시하고 빈자리는 0으로 채우기
			if (i % 2 == 1)
			{
				printf(" "); // 2bytes마다 space
			}
			if ((i + 11) % 16 == 0)
			{
				printf("\n"); // 16bytes마다 enter
			}
		}
	}
	printf("\n");
}

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
	if (pcap_compile(fp,											 // pcap handle
					 &fcode,										 // compiled rule
					 (char *)("host 165.246.38.151 and port 12520"), // 캡처할 ip 및 port 번호 지정
																	 // filter rule
					 1,												 // optimize
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

		print_raw_packet(pkt_data, header->caplen);
		// print_ether_header(pkt_data);
		// print_ip_header(pkt_data);
		// print_tcp_header(pkt_data);
		// print_data(pkt_data, header->caplen);

		// 1-1-1), 1-2-1)
		printf("\nNow breaking this loop\n");
		break; // 1-1-1), 1-2-1) break out of the while loop after capturing the first SYN packet.
	}

	// 1-2-2) copy them into another buffer: pkt_data=>packet
	const unsigned char *packet = (unsigned char *)malloc(65535);
	packet = pkt_data;

	// 1-2-3)
	struct ip_header *ih = (struct ip_header *)(pkt_data + 14);
	struct tcp_header *th = (struct tcp_header *)(pkt_data + 14 + 20);
	// 1-2-3) set ip_check_sum and tcp_check_sum to zero
	ih->ip_checksum = 0;
	th->checksum = 0;

	// 1-2-4), 1-2-5)
	int tcp_length = th->data_offset * 4;

	struct pseudo_header psh;
	// to use inet_pton(), include "winsock2.h" and "ws2tcpip.h" in windows
	// in MacOS, include <arpa/inet.h>
	inet_pton(AF_INET, IP_OF_YOUR_PC, &(psh.source_address)); // ip of your pc
	inet_pton(AF_INET, IP_OF_DEST, &(psh.dest_address));	  // dest ip
	psh.placeholder = 0;									  // reserved
	psh.protocol = 6;										  // protocol number for tcp
	psh.tcp_length = htons(tcp_length);						  // store multi byte number in network byte order

	unsigned char *seudo;
	seudo = (unsigned char *)malloc(sizeof(struct pseudo_header) + tcp_length);
	memcpy(seudo, &psh, sizeof(struct pseudo_header));
	memcpy(seudo + sizeof(struct pseudo_header), th, tcp_length);

	// 1-2-4), 1-2-5) recompute ip_check_sum and tcp_check_sum
	ih->ip_checksum = in_checksum((unsigned short *)ih, 20);
	th->checksum = in_checksum((unsigned short *)seudo, sizeof(struct pseudo_header) + tcp_length);

	// 1-1-2) now we have syn packet in pkt_data
	printf("\nLet's send SYN ===========\n");
	printf("Checking TCP header length : %d\n", tcp_length);
	printf("Length of SYN packet       : %d\n", header->caplen); // header : struct pcap_pkthdr
	print_raw_packet(pkt_data, header->caplen);					 // 1-2-6) display the packet in raw bytes.
																 // this should be same as pkt_data

	// 1-1-3), 1-2-7) kill the server and the client (manually)
	printf("\nKill server and the client.\n");
	// 1-1-4), 1-2-8) run the original sniffer
	printf("Run the original sniffer.\n");
	// 1-1-5), 1-2-9) rerun the server
	printf("Rerun the server and hit '9' when ready : ");
	int x;
	scanf("%d", &x);

	if (x == 9)
	{
		// 1-1-6), 1-2-10) send the captured SYN packet to the server
		printf("\nNow we send our SYN. See if we receive ACK from the server.\n");
		if (pcap_sendpacket(fp, pkt_data, 14 + 20 + tcp_length) != 0)
		{
			printf("err in packet send : %s\n", pcap_geterr(fp));
		}
	}

	return 0;
}
