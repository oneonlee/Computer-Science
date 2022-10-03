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
  - [client-server](#client-server-architecture)
  - peer-to-peer (P2P)

#### Client-server architecture

- server:
  - always-on host
  - permanent IP address
  - data centers for scaling
- clients:
  - communicate with server
  - may be intermittently connected
  - may have dynamic IP addresses
  - do not communicate directly with each other

#### P2P architecture

- no always-on server 
- arbitrary end systems directly communicate
- peers request service from other peers, provide service in return to other peers
  - self scalability – new peers bring new service capacity, as well as new service demands
- peers are intermittently connected and change IP addresses
  - complex management

---

Source : <br>
**Computer Networking: A Top Down Approach** 6th edition - Jim Kurose, Keith Ross Addison-Wesley March 2012
