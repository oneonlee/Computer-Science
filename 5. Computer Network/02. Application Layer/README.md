# Application Layer

overview:

- principles of network applications
- Web and HTTP
- FTP
- electronic mail(SMTP, POP3, IMAP)
- DNS
- P2P applications

our goals:

- conceptual, implementation aspects of network application protocols
  - transport-layer service models
  - client-server paradigm
  - peer-to-peer paradigm
- learn about protocols by examining popular application-level protocols
  - HTTP
  - FTP
  - SMTP / POP3 / IMAP
  - DNS

## 1. principles of network applications

### Application architectures

- possible structure of applications:
  - [client-server](#client-server-architecture) (일반적으로 client가 먼저 요청)
  - peer-to-peer (P2P)

#### Client-server architecture

- server:
  - always-on host
  - **permanent** IP address
  - data centers for scaling
- clients:
  - communicate with server
  - may be intermittently connected
  - may have **dynamic** IP addresses
  - do not communicate directly with each other

#### P2P architecture

- no always-on server (항상 켜져 있는 서버가 없음)
- arbitrary end systems **directly** communicate
- peers request service from other peers, provide service in return to other peers
  - self **scalability** – new peers bring new service capacity, as well as new service demands
- peers are intermittently connected and change IP addresses
  - complex management

### Processes communicating
process: program running **within a host**
- within same host, two processes communicate using inter-process communication (defined by OS)
- processes in different hosts communicate by exchanging messages
- aside: applications with P2P architectures have client processes & server processes
- clients, servers
  - client process: process that initiates communication
  - server process: process that waits to be contacted

### Sockets
- process sends/receives messages to/from its socket
- socket analogous to door
  - sending process shoves message out door
  - sending process relies on transport infrastructure on other side of door to deliver message to socket at receiving process

### Addressing processes
- to receive messages, process must have identifier
- host device has unique 32- bit IP address
- Q: Does IP address of host on which process runs suffice for identifying the process?
  - A: no, many processes can be running on same host
- identifier includes both IP address and port numbers associated with process on host.
- example port numbers :
  - HTTP server: 80
    - - mail server: 25
  - (well-known port number : 1번부터 1023번까지 번호가 미리 할당됨)
    - client는 well-known port number를 사용하지 않아도 됨
- to send HTTP message to gaia.cs.umass.edu web server:
  - IP address: 128.119.245.12 (Host 지칭)
  - Port number: 80 (Process 지칭)
- more shortly...

### App-layer protocol defines

- types of messages exchanged,
  - e.g., request, response
- message syntax:
  - what fields in messages & how fields are delineated 
- message semantics
  - meaning of information in fields
- rules for when and how processes send & respond to messages<br><Br>
- open protocols:
  - defined in RFCs
  - allows for interoperability
  - e.g., HTTP, SMTP 
- proprietary protocols:
  - e.g., Skype

### What transport service does an app need?
#### data integrity throughput
some apps (e.g., file transfer, web transactions) require 100% reliable data transfer
other apps (e.g., audio) can tolerate some loss

#### timing
some apps (e.g., Internet telephony, interactive games) require low delay to be “effective”

#### throughput
- some apps (e.g., multimedia) require minimum amount of throughput to be “effective”
- other apps (“elastic apps”) make use of whatever throughput they get

#### security
- encryption, data integrity,
---

Source : <br>
**Computer Networking: A Top Down Approach** 6th edition - Jim Kurose, Keith Ross Addison-Wesley March 2012
