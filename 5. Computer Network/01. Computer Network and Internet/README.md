# Computer Network and Internet

overview:

- [What’s the Internet and protocol?](#1-what-is-the-internet-and-protocol)
- [Network Topology and Layout](#2-network-topology-and-layout)
- [Network Structure](#3-network-structure)
  - [1) Network Edge device](#3-1-network-edge-네트워크-에지-네트워크-가장자리)
  - [2) Network Core device](#3-2-network-core)
  - [3) Access Networks](#3-3-access-networks-접속-네트워크)
- [Performance in network: loss, delay](#4-delay-loss-in-networks)
- [Protocol layers](#5-protocol-layers-osi-7-layer)

## 1. What is the Internet and Protocol?

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/network.png)

### 인터넷(Internet)이란?

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/network.png)

- Internet : 수백만 개의 연결된 컴퓨팅 장치
  - **hosts** = end systems (종단 시스템)
  - 네트워크 application을 실행한다.
- 인터넷은 ISP(Internet Service Provider)가 상호 연결되었기 때문에 "네트워크의 네트워크"라고도 불린다.
- communication links (통신 링크)
  - transmission rate (전송 속도) : **bandwidth** (대역폭)
  - device와 device를 연결하는 매체가 유선인지 무선인지에 따라 구분할 수 있다.
    - 광섬유, 구리, [라디오](https://ko.wikipedia.org/wiki/%EB%9D%BC%EB%94%94%EC%98%A4), 위성(satellite)
    - 매질에 따라 bandwidth가 달라진다.
- **Packet switches** or **Packet routers** : 패킷(데이터 덩어리) 전달

#### 서비스 관점에서의 인터넷(Internet)

- application에 서비스를 제공하는 인프라(infrastructure)
  - Web, VoIP, email, 게임, 전자 상거래, 소셜 네트워크, …
- 앱에 프로그래밍 인터페이스 제공
  - 인터넷에 "연결"하기 위해 앱 프로그램을 주고받는 것을 허용
    - e.g., 소켓 프로그래밍
  - 비유 : 우편 서비스와 유사한 서비스 제공
    - 우편 집배원은 편지 내용을 보지 않고 고객에게 전달만 한다.
    - 마찬가지로, end-system만이 application을 사용한다.

### 프로토콜(protocol)이란?

- 프로토콜은 형식, 네트워크 엔터티 간에 송수신되는 메시지 순서 및 메시지 전송, 수신에 대해 수행되는 작업을 제어한다.
  - e.g., TCP, IP, HTTP, Skype, 802.11
- Internet standards (인터넷 표준)
  - RFC: Request for comments
  - IETF: Internet Engineering Task Force (Internet standards를 만드는 기관)

사람 간의 프로토콜과 컴퓨터 네트워크의 프로토콜 비교 : <br>
![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/protocol.png)

## 2. Network Topology and Layout

### 2-1) Mesh Network

![](https://upload.wikimedia.org/wikipedia/commons/thumb/9/97/NetworkTopology-Mesh.svg/1920px-NetworkTopology-Mesh.svg.png)

- wiring이 복잡하여 현실적이지 않음

### 2-2) Bus

![](https://upload.wikimedia.org/wikipedia/commons/thumb/4/47/BusNetwork.svg/440px-BusNetwork.svg.png)

- broadcasting 효과가 발생하여 수신자와 발신자를 표시하는 Addressing이 필요하다.
- 자기한테 온 data가 아닐 경우 계속해서 폐기해야 한다.
- 동시에 송신 시, 1명만 가능하다.

### 2-3) (Dummy) Hub

![](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d0/StarNetwork.svg/440px-StarNetwork.svg.png)

- Star Topology 구조를 사용하며, 논리적으로 Bus의 구조를 띈다.
- 노이즈가 쌓이는 것을 방지한다.

### 2-4) Bridge

![](https://www.rfwireless-world.com/images/network-bridge.jpg)

- Bridge가 각 호스트의 위치가 어디에 있는지 알기 때문에 충돌이 일어날 수 있는 도메인(collision domain)을 분리할 수 있음
  - 알 수 있는 방법
    - (1) 하드 코딩
    - (2) self-learning

### 2-5) Switch

![](https://book.systemsapproach.org/_images/f03-02-9780123850591.png)

- Bridge처럼 위치 정보를 얻는다.
- Collision Domain을 많이 구성할 수 있다.
- 처리 속도가 빠르다.
- 통상, Address는 Logical Address와 Physical Address로 구분된다.
  - (1) Logical Address
    - e.g., IP Address
  - (2) Physical Address
    - = Hardware Address = MAC Address
    - Switch는 이 개념을 사용한다.
    - Hardware 상에서 주소 일치 여부를 테이블을 통해 확인한다.

### 2-6) Router

![](http://www.deadfire.net/tcpip/router.gif)<br>
![](https://mblogthumb-phinf.pstatic.net/20160518_55/ehdrhs1004_14635632108579vcg9_PNG/051816_0920_24.png?type=w2)

- 라우터(Router)는 네트워크와 네트워크를 연결하는 장치로 목적지까지의 최적 경로를 결정하여 라우팅(Routing)해주는 장치이다.
- Logical Address(IP Address)를 판단하여 데이터를 주고받는다.

#### Router의 기본 알고리즘 - Routing과 Forwarding

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/network-core%20functions.png)

라우터는 데이터의 목적지 주소를 보고, local forwarding table을 참조하여 어느 경로를 통해 데이터를 전송해야 할지 판단한다. 이 때, 판단해서 보내는 기능을 **Forwarding**이라고 하고, local forwarding table을 만드는 기능을 **Routing**이라고 한다.

##### Routing

- 데이터를 송신하는 호스트는 패킷을 라우터로 보낼 때 각 패킷마다 헤더에 목적지(end system)의 정보를 포함시킨다. 라우터는 패킷의 헤더를 통해, source부터 destination까지 가는 경로를 결정한다.
- 이 때 사용되는 것이 local forwarding table이다.
- local forwarding table은 라우터들끼리 만들어야한다.
  - 데이터의 송수신이 발생하기 전에 라우터들끼리 미리 정보를 주고받는다.
  - 그래서 라우터들끼리 누가 존재하고 누가 연결되어 있고 어디로 보낸게 가장 합리적인지 미리 결정(routing algorithm)한다.
  - 그리고 이것을 forwarding table로 만든다.
  - 이후 패킷이 오면 forwarding table에 근거하여 내보내는 일을 진행할 수 있다.

##### Forwarding

- 어느 경로로 가야할 지 local forwarding table을 보고 판단하여 경로를 알아내면, link를 통해서 패킷을 그 곳으로 보내주는 역할을 한다.
- local forwarding table에서 packet header로 이동할 라우터를 찾으면, 그 라우터에 들어온 data의 output link가 결정된다.

## 3. Network Structure

## 3-1) Network Edge (네트워크 에지, 네트워크 가장자리)

- 인터넷의 말단 부분이다. 즉, 여러개의 네트워크로 이루어진 인터넷에서 **말단 부분에 위치한 네트워크**이다.
- 모바일 네트워크, 홈 네트워크, 기관 네트워크 일반적 사용자들이 존재하고 있는, 사용자들이 직접 접하고 있는 네트워크이다.
- 이러한 네트워크 엣지의 말단 부분을 **Host**(End System)라고 부른다.
  - 참고로, Host의 종류에는 클라이언트와 서버 등이 있다.
    - 클라이언트 : 서비스를 요청하는 자
    - 서버 : 서비스를 제공하는 자

### Host: sends packets of data

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/host.png)

- host sending function:
  - takes application message
  - breaks into smaller chunks, known as packets, of length L bits
  - transmits packet into access network at transmission rate R
    - link transmission rate, aka link capacity, aka link bandwidth

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/delay.png)

## 3-2) Network Core:

우리가 통신을 하려면 네트워크 가장자리에 있는 컴퓨터들(host)끼리 연결이 되어야 한다. 이 연결을 제공해주는 중간 역할을 하는 부분이 Network Core이다. 한 마디로 "Network of Networks"이며, 서로서로 연결되어 있는 라우터들의 집합체이다.

네트워크에는 수많은 패킷들이 돌아다니는데, 송신 측과 수신 측 사이에서 각 패킷은 통신 링크와 패킷 스위치를 거치게 된다.

link와 router에서 데이터(패킷)가 이동하는 통신 방식에는 두가지가 있다. [Packet switching(패킷 교환) 방식](#packet-switching--store-and-forward)과 [Circuit switching(회선 교환)](#circuit-switching) 방식이다.

### Packet switching : store-and-forward

Packet switching은 store-and-forward(저장 후 전달 방식)을 채택한다. store-and-forward 방식은 '전송될 모든 패킷이 라우터에 도착해야(store), 패킷의 첫 비트가 next link로 전송된다(forward)'는 개념이다.

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/packet-switching.png)

위 그림에서 1번 패킷이 라우터로 전송되고 있다. 절반 정도까지만 전달됐기 때문에, 이 1번 패킷이 출력되기 위해서는 나머지 절반을 모두 다 받아야지(즉 1번 패킷의 모든 비트를 다 받아야지만) 내보낼수 있다는 소리이다.

- Packet switching으로 source에서 destination까지 1번 패킷이 전달될 때 걸리는 시간을 계산해보자. 각 링크는 초당 R bps의 속도로 패킷을 전송하고, 각 패킷은 L bit이다. (전파지연은 무시)
  - (1) 앞서 설명한 것처럼 한 패킷의 모든 bit가 라우터에 다 도착할 때까지, 이미 도착해 있는 1번 패킷의 일부 비트들은 다음 링크로 출발하지 못하고 기다려 주어야 한다.
  - (2) 그러므로 1번 패킷이 라우터에 다 도착하여 저장이 완료되면, 그 시간은 1L/R초이다.
  - (3) 1L/R 초에서 2L/R 초가 될 동안, 첫번째 패킷은 destination으로 연결된 링크를 타고 전송되고, source에서는 두번째 패킷이 라우터를 향해 출발한다.
  - (4) 그렇다면 2L/R 초가 흐르면,
    - 1. 1번 패킷은 destination에 있고
    - 2. 2번 패킷은 라우터에 저장이 완료(모든 비트들이 도착)된다.
    - 즉, 1번 패킷이 destionation에 도착하면 end-end delay가 **2L/R** 초가 된다는 뜻이다. (전파 지연은 무시)
      - 만약 store-and-forward 방식이 아니였더라면, 지연이 발생하지 않으므로 end-end delay는 1L/R초가 된다는 것도 알아두면 좋다.

### Packet switching: queueing delay, packet loss

이전 그림처럼 라우터를 사이에 둔 두 링크가 모두 같은 속도라면 좋겠지만, 대부분은 그렇지 않다. 만약, 출력링크로 패킷을 내보내는 속도가 패킷이 라우터로 들어오는 속도보다 느리다면 라우터에는 queue가 생기며, 시간이 흘러 이 큐는 패킷을 받아들일 저장공간이 부족하여 넘치게 될 것이다. 방금 한 얘기에 대한, 2가지 개념이 있다.

#### 1) queueing delay

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/queue%20of%20packets.png)

각 패킷 스위치(라우터)는 접속 된 여러 개의 링크를 가진다. 각 링크에 대해 패킷 스위치는 출력 버퍼를 갖고 있으며, 그 링크로 송신하려고 하는 패킷을 저장하고 있다. 만약 버퍼에 도착한 패킷이 출력 링크로 나가야 하는데 그 해당 링크가 이미 다른 패킷을 내보내고 있다면 도착한 패킷은 버퍼에서 대기해야한다. 이렇게 도착하는 패킷이 버퍼에서 대기하는 상황을, **queueing delay**라고 한다.

#### 2) packet loss (drop)

버퍼의 용량은 한정적이므로 이 버퍼가 넘치면 방금 도착한 패킷이나 이미 저장되어 있는 패킷은 버퍼에 들어가지 못하고, 패킷이 버려지는 손실이 발생한다.

### Circuit switching

링크와 스위치의 네트워크를 통해 데이터를 이동시키는 방식에는 Packet switching 방식 이외에도 Circuit switching(회선교환) 방식이 있다.

Circuit switching 방식에서는 종단 시스템 간에 통신을 제공하기 위해 경로상에 필요한 자원은 세션이 유지되는 동안에는 **예약**되어야 한다.

Circuit switching 네트워크의 예로는 전통적인 전화망이 있다. 어떤 사람이 전화망을 통해 다른 사람에게 정보를 보내려고 할 때 어떤 일이 일어나는지 생각 해보자.

> 일단 내가 친구한테 전화를 하려면 수화기를 들고 번호를 입력한다. 번호를 입력하고 친구가 전화를 딱 받는 순간! 해당 전화망은 아무도 쓰지 못하고 오로지 나만 쓸수 있다는 것이다. 이렇게 연결이 예약된 상태에서 전화를 하게된다면 송신자는 수신자에게 보장된 일정 전송률로 데이터를 보낼수 있다는 장점이 있다. 하지만 연결 동안에는 다른 사람이 사용하지 못하는 단점이 있다. 전화를 하는 도중 다른 친구가 나한테 전화를 해도 '상대방이 통화중입니다' 라는 소리가 나오는 것처럼 말이다. <br>
> source와 destination 사이의 경로를 정해버리면 **queueing delay 완화**되고 중간에서의 **손실도 줄어든다**. 하지만 문제는 경로를 설정해놨는데 **사용을 안한다면 낭비**가 된다. 그렇다면 계속 데이터를 주고받아야 한다. 아하! 전화에 적합하구나! 해서 Circuit-switching은 전화를 위해 개발된 것이다.<br>
> 만약 친구와 통화를 한다면, 내 목소리와 친구의 목소리가 흘러가는 경로가 미리 준비되어 있을 것이다.

내용 출처 : https://wogh8732.tistory.com/14, https://inyongs.tistory.com/48

- Circuit switching의 특징을 정리하면 아래와 같다.
  - (1) 미리 경로를 예약하여 사용한다.
  - (2) 자원을 공유하지 않아 독립적이다.
    - 통신의 **품질이 안정적으로 유지되고 보장**된다. (guaranteed)
  - (3) delay와 loss가 완화된다. (라우터에 도착하는 패킷은 미리 지정된 경로로 빠르게 전송되기 때문에)
  - (4) Bandwidth를 고정하면 사용자의 수가 정해져 있어서, 자원이 없으면 연결이 안된다.

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/circuit-switching.png)

위 그림에서 굵은 초록색의 회선을 두 호스트가 사용하게 되면 다른 호스트 들은 이 회선을 사용하지 못한다. 각 링크가 4개의 회선을 가지므로 라우터 간에 1Mbps의 전송속도를 갖는다면 각 회선 교환 연결은 250kbps의 속도를 얻게 된다.

#### Circuit switching의 구현 방법 - FDM, TDM

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/FDMvsTDM.png)

- FDM (frequency division multiplex, 주파수 분할 다중 방식)

  - 주파수 단위로 쪼개는 것.

- TDM (time division multiplex, 시간 분할 다중 방식)
  - 시간 단위로 쪼개는 것

### Packet switching vs. Circuit switching

|      | Packet switching                                                                                                                                                                                                                                                                                                                                                                                                                                       | Circuit Switching                                                                                                                                                                                                                                                                                       |
| ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 장점 | <ul> <li>약간의 성능 저하로 훨씬 더 많은 사용자들이 사용 가능하다.</li> <li>주고받는 데이터를 패킷 단위로 자르고, 그 패킷들을 섞어서 보냄으로써 <br>데이터가 전달되는 경로를 효율적으로 이용하여 link의 낭비가 줄일 수 있다.</li> <li>Circuit Switching보다 전송용량의 공유에서 더 효율적이다.</li> <li>Circuit Switching보다 더 간단하고, 구현 비용이 더 적게 든다.</li> <li>데이터의 전송 간격이 불규칙한 데이터(bursty data)에 적합하다.</li> </ul> | 경로를 지정함으로써 아래와 같은 장점들을 얻을 수 있다. <ul> <li>queueing delay가 완화되고, 일정한 전송률을 보장받는다.</li> <li>장시간 긴 데이터를 보낼 때 신뢰있는 전송을 보장받을 수 있다.</li> <li>제한된 시간에 빠르게 보낼 때 더 낫다.</li> <li>다른 사용자와 공유하지 않아 독립적이다.</li> </ul> |
| 단점 | <ul> <li>가변적이고 예측할 수 없는 종단간의 지연 때문에 streaming data(전화, 화상회의 등)에는 적당하지 않다.</li> <li>혼잡이 발생하여 delay와 loss가 발생하지만, control 할 수 없다.</li> </ul>                                                                                                                                                                                                                                                        | <ul> <li>데이터를 주고받지 못하는 경우가 생길 때, link의 낭비가 발생된다.</li> </ul>                                                                                                                                                                                                                    |

## 3-3) Access Networks (접속 네트워크):

- 접속 네트워크란 말 그대로, **네트워크에 접속하는 네트워크**를 뜻한다.
- Host(End System)가 Network Core에 접속하는데에 도움을 주는 **중간 단계 네트워크**이다.
- e.g., 유선(랜선), 무선 통신 링크(와이파이) 등
  - 유선으로 네트워크에 접속하기 위해선 랜선을 꼽아서 사용해야 하고, 무선으로 네트워크에 접속하기 위해서는 와이파이를 이용하여 네트워크에 접속해야한다.

### End System을 Edge Router에 연결하는 방법

- 집 : Residential Access Network 설치
  - ![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/home%20net.png)
- 학교, 회사, 기관 등 : Institutional Access Networks, Enterprise Access Networks (Ethernet) 설치.
  - ![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/ethernet.png)
  - 전송 속도 : 10Mbps, 100Mbps, 1Gbps, 10Gbps 등
  - End System은 일반적으로 Ethernet switch에 연결된다.
- 기지국 : Mobile Access Networks를 설치.

### Wireless access networks (무선 액세스 네트워크)

wireless access network는 "access point"라고 불리는 기지국을 통해 end system을 router로 연결시킨다. 말 그대로 '무선'에 초점을 맞춘 개념이다.

wireless access network에는 크게 두 가지 종류가 있다.

#### (1) Wireless LANs (무선랜):

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/wireless%20LANs.png)

LAN은 Local Area Network의 약자로 local area 내에 device가 연결될 때 그것을 LAN이라고 한다.

이는 하나의 빌딩, 오피스, 집을 무선으로 연결시키는 것이고 이 때 사용하는 것이 802.11에서 나오는 각종 wifi protocol인 것이다.

- 유효 거리
  - 건물내 (100 ft = 약 30.5m)
- 전송 속도 (transmission rate)
  - 802.11b/g (WiFi): 11, 54 Mbps

#### (2) Wide-area Wireless Access

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/wide-area%20wireless%20access.png)

wide area network를 의미하고 LAN보다 더 넓은 개념이다.

통신사 셀룰러 사업자가 제공하는 서비스이며, 3G, 4G, LTE 등 다양한 것이 나왔는데 이는 wireless LAN보다는 속도가 느리지만 참고로 6G로 가면 유선 광케이블 정도까지 속도를 높일 수 있다고 한다.

- 유효 거리
  - 약 10km
- 전송 속도 (transmission rate)
  - between 1 and 10 Mbps

## 4. delay, loss in networks

### Packet Switching에서의 4가지 지연 원인

앞서 설명하였듯, Packet Switching(패킷 교환)은 store-and-forward(저장 후 전달 방식)을 채택한다. store-and-forward 방식은 '전송될 모든 패킷이 라우터에 도착해야(store), 패킷의 첫 비트가 next link로 전송된다(forward)'는 개념인데, 이 때문에 queueing delay가 발생된다.

Packet Switching에는 queueing delay 이외에도 여러가지 요인들로 지연이 발생되는데, Packet Switching에서의 지연 원인을 크게 4가지로 정리해보면 아래와 같다.

- 1. Processing delay (처리 지연)
- 2. Queueing delay (큐잉 지연)
- 3. Transmission delay (전송 지연)
- 4. Propagation delay (전파 지연)

따라서 전체 노드 지연은 d(nodal, 전체) = d(proc, 처리) + d(queue, 큐잉) + d(trans, 전송) + d(prop, 전파)으로 표현한다.

​위 4종류의 지연에 대해 자세히 살펴 보자.

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/sources%20of%20packet%20delay.png)

#### (1) Processing delay (처리 지연)

Processing 과정은 라우터 내에서 패킷이 진행하는 과정이다. 이 과정에서 패킷 데이터의 bit error를 검사하고, 그 패킷을 어디로 보낼지를 결정하는데에 발생하는 지연을 Processing delay라고 한다.

> 비유 1 : 소총 사격 시, 탄약 관리 간부들이 탄약의 이상 여부를 검사하고(우상탄 10발 이상무), 탄알집을 병사들에게 인계하는 시간.
> <br>
> 비유 2 : 놀이공원에 갔는데 롤러코스터를 타려면 어디로 어떻게 갈지 결정하는 시간.

Processing delay는 매우 짧은 시간동안만 발생하며, 라우터 내의 하드웨어의 성능, 혹은 라우터의 알고리즘에 따라 좌지우지되므로 가변적이지 않다는 특징이 있다. 고속 라우터에서의 Processing delay는 일반적으로 수 msec이다.

#### (2) Queueing delay (큐잉 지연)

라우터로 패킷들이 한번에 많이 들어올 경우, 라우터는 패킷들을 queue 형태로 보관하여 차례대로 처리한다. 이때, 전송을 위해 output link의 queue에서 기다리면서 발생하는 지연을 Queueing delay라 한다.

> 비유 1 : (특정 탄약의 입장에서) 탄알집 결합 후, 탄약이 탄알집에서 발사되기까지 순서를 기다리는 시간.
> <br>
> 비유 2 : 롤러코스터를 타러 갔는데 앞서 도착한 사람들이 있어 대기하는 시간.

Queueing delay는 라우터의 congestion(혼잡) 정도, 즉 앞서 도착하여 기다리는 다른 패킷들의 수에 의해 결정된다.

만일 queue가 비어있고 다른 패킷이 전송 중인 상태가 아니라면 패킷의 Queueing delay은 0이다. 반면 트래픽이 많고 다른 많은 패킷이 전송 대기 중이면, Queueing delay는 매우 길어진다.

이렇듯, Queueing delay는 상황에 따라 가변적이라 예측이 어렵다는 특징이 있다.

#### (3) Transmission delay (전송 지연)

- d_trans: transmission delay:
  - L: packet length (bits)
  - R: link bandwidth (bps)
  - d_trans = L/R

queue를 빠져나가 라우터의 output link를 통해 빠져나가기 전까지 발생하는 delay이다. 즉, 전송하려는 패킷을 output link로 밀어내는데 걸리는 시간이다.

> 비유 1 : '노리쇠 전진', '조정간 단발'에 걸리는 시간.
> <br>
> 비유 2 : 롤러코스터에 탑승할 차례가 되어 자리에 앉기까지 걸리는 시간.

Transmission delay는 link의 bandwidth (link가 최대로 전송할 수 있는 데이터 양) 에 따라 결정되며, link bandwidth는 불변값이고 패킷의 길이도 대부분 비슷하므로 Transmission delay도 비교적 가변적이지 않다는 특징이 있다.

참고로, 여기서 가변적이지 않다는 말은 1개의 패킷을 기준으로 계산했을 때 가변적이지 않다는 뜻이다. 실제 상황에서 Transmission delay는 보내는 데이터의 양에 따라서 매우 가변적으로 변한다.

Transmission delay = (Packet Length) / (link bandwidth) 로 계산한다.

#### (4) Propagation delay (전파 지연)

실제 link를 타고 데이터가 전송될 때, link의 처음부터 라우터까지의 전파에 필요한 시간(delay)이다.

> 비유 1 : 탄알이 격발되어, 목표물을 타격하는 데까지 소요되는 시간.
> <br>
> 비유 2 : 롤러코스터가 출발해서 한 코스를 도는 시간.

Propagation delay는 거리와 link의 매체가 결정하는 delay로, 다른 delay에 비해 매우 짧은 시간이 걸린다. 특히나 요즘같이 광통신을 하는 경우에는 거의 없다고 봐도 될 정도로 짧다.

Propagation delay = (distance) / (Propagation speed) 로 계산한다.<br>
출발지와 목적지 라우터 사이의 거리가 d이고 v가 link의 전파속도라면, 전파 지연은 d/v이다.

##### Transmission delay vs. Propagation delay

- Transmission delay는 라우터가 패킷을 내보내는데 필요한 시간으로, 두 라우터 사이의 거리와 상관없다.
- Propagation delay는 패킷이 한 라우터에서 다음 라우터까지 이동(전파)하는데 필요한 시간이다. 패킷 길이나 전송률과 상관이 없다.

### Queueing delay (큐잉 지연)

- R: link bandwidth (bps)
- L: packet length (bits)
- a: average packet arrival rate

라고 할 때, traffic intensity(트래픽 강도)는 La/R로 계산할 수 있다.

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/queuding%20delay.jpg)<br>
traffic intensity(트래픽 강도)가 1에 접근할수록 평균 큐잉 지연이 급속히 증가한다.

- La/R ~ 0: avg. queueing delay small
- La/R <= 1: avg. queueing delay large
- La/R > 1: more “work” arriving than can be serviced, average delay infinite!

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/La%3AR.png)

<!-- ### “Real” Internet delays and routes

- what do “real” Internet delay & loss look like?
- `traceroute` program: provides delay measurement from source to router along end-end Internet path towards destination. For all i:
  - sends three packets that will reach router i on path towards destination
  - router i will return packets to sender
  - sender times interval between transmission and reply. -->

### Packet loss (패킷 손실)

- 현실에서 queue (aka buffer)의 용량은 스위치 설계와 비용에 크게 의존하며, 일반적으로 유한한 용량을 가진다.
- queue 용량이 유한하므로, 패킷이 도착했을 때 queue가 꽉 찬다면 문제가 발생한다.
- 이렇게 패킷을 저장할 수 없는 경우에 라우터는 그 패킷을 버린다.
- 종단 시스템(Host) 관점에서 패킷 손실은 패킷이 네트워크 코어로 전송되었으나 네트워크로부터 목적지에 나타나지 않는 것으로 보일 것이다.
- 손실 패킷의 비율은 traffic intensity(트래픽 강도)가 클수록 증가한다.

<!-- ### Throughput

- throughput: rate (bits/time unit) at which bits transferred between sender/receiver
  - instantaneous: rate at given point in time
  - average: rate over longer period of time -->

## 5. Protocol layers (OSI 7 Layer)

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/iso%3Aosi-reference-model.png)

- Protocol layers는 네트워크 프로토콜이 통신하는 구조를 7개의 계층으로 분리하여 각 계층간 상호 작동(언제, 어떻게, 어떤 내용을 통신)하는 규정하는 규칙이다.
- ISO(국제표준화기구)에서 **OSI 7 계층(OSI 7 Layer)**로 표준화하였다.
- 각 layer에는 아래 표처럼 각각의 서비스가 구현되어 있다.

| Layer No. | Layer Name   | Description                                                                                               |
| --------- | ------------ | --------------------------------------------------------------------------------------------------------- |
| 7         | Application  | Consists of standard communication services and applications that everyone can use.                       |
| 6         | Presentation | Ensures that information is delivered to the receiving machine in a form that the machine can understand. |
| 5         | Session      | Manages the connections and terminations between cooperating computers.                                   |
| 4         | Transport    | Manages the transfer of data. Also assures that the received data are identical to the transmitted data.  |
| 3         | Network      | Manages data addressing and delivery between networks.                                                    |
| 2         | Data Link    | Handles the transfer of data across the network media.                                                    |
| 1         | Physical     | Defines the characteristics of the network hardware.                                                      |

- layer를 쓰는 이유
  - 기능별로 나누어 두었기 때문에 이해/구현이 편하다.
  - 문제가 있을 시, 한 개의 layer만 해결하면 되므로 발전시키기 좋고 관리가 편하다.
  - 인터넷 연결은 엄청나게 복잡한 시스템인데, layer처럼 구분되어 있는 구조는 다른 layer의 동작에 영향을 주지 않는 장점이 있다.
- layer를 더 세분화 할 수 있었겠지만, layer가 너무 많다면 데이터 앞에 있는 헤더가 쌓이면서 데이터의 길이보다 길어지게 될 것이다.

### Internet protocol stack (인터넷 프로토콜 스택)

![© All material copyright 1996-2012 J.F Kurose and K.W. Ross, All Rights Reserved](img/internet_protocol.png)

#### application layer (애플리케이션 계층)

- 애플리케이션 계층은 **네트워크 애플리케이션**과 **애플리케이션 계층 프로토콜**이 있는 곳이다.
- 인터넷의 애플리케이션 계층은 아래와 같이 많은 프로토콜을 포함한다.
  - **HTTP** (웹 문서 요청과 전송을 위해 제공)
  - **SMTP** (전자메일 전송을 제공)
  - **FTP** (두 종단 시스템 간의 파일 전송 제공)

#### transport layer (트랜스포트 계층)

- 인터넷의 트랜스포트 계층은 클라이언트와 서버 간에 애플리케이션 계층 메시지를 **전송**하는 서비스를 제공한다.
- 인터넷에는 **TCP**와 **UDP**라는 2가지 트랜스포트 프로토콜이 있으며, 이들은 애플리케이션 계층 메시지를 전달한다.
  - TCP는 애플리케이션에게 연결지향형 서비스를 제공한다.
    - 이 서비스는 목적지로의 애플리케이션 계층 메시지 전달 보장과 흐름 제어(송신자/수신자의 속도 일치)를 포함한다.
  - 또한 TCP는 긴 메시지를 짧은 메시지로 나누고 혼잡 제어 기능을 제공하여, 네트워크가 혼잡할 때 출발지의 전송 속도를 줄이도록 한다.
  - UDP는 애플리케이션에 비 연결형 서비스를 제공한다.
    - 이 서비스는 신뢰성, 흐름 제어, 혼잡 제어를 제공하지 않는 아주 간단한 서비스이다.

#### network layer (네트워크 계층)

- 인터넷의 네트워크 계층은 한 호스트에서 다른 호스트로 데이터그램(datagram)을 **라우팅**하는 책임을 가진다.
- 인터넷의 네트워크 계층은 아래의 두 가지 주요 요소를 갖는다.
  - **인터넷 프로토콜** (**IP**, **I**nternet **P**rotocol): IP 데이터그램의 필드를 정의하며 종단 시스템과 라우터가 이 필드에 어떻게 동작하는지를 정의한다.
  - **라우팅 프로토콜**: 출발지와 목적지 사이에서 데이터그램이 이동하는 경로를 결정한다.
- 비록 네트워크 계층이 인터넷 프로토콜과 여러 라우팅 프로토콜을 모두 갖고 있지만, IP가 인터넷을 함께 묶는 역할을 한다는 사실을 반영하여 흔히 IP Layer라고 불린다.

#### link layer (링크 계층)

- 링크 계층은 인접한 네트워크 노드끼리 데이터를 전송하는 기능과 절차를 제공한다.
- 링크 계층 프로토콜의 예로는 이더넷, 802.111 (WiFi) 등이 있다.

#### physical layer (물리 계층)

- 링크 계층의 기능이 전체 프레임을 한 네트워크 요소에서 이웃 네트워크 요소로 이동하는 것이라면, 물리 계층의 기능은 프레임 내부의 각 비트를 한 노드에서 다음 노드로 이동하는 것이다.
- 이 계층의 프로토콜들은 링크에 의존하고 더 나아가 링크의 실제 전송 매체(e.g., 광케이블, 동축케이블)에 의존한다.
  - 예를 들어, 이더넷은 여러 가지 물리 계층 프로토콜을 갖고 있다.(광케이블 프로토콜, 동축케이블 프로토콜 등)
- 각각의 경우에 비트는 다른 방식으로 링크 반대편으로 이동된다.

---

## Source :

1. **Computer Networking: A Top Down Approach** 6th edition - Jim Kurose, Keith Ross Addison-Wesley March 2012
2. https://lyres.tistory.com/40
3. https://wogh8732.tistory.com/14
4. https://ddongwon.tistory.com/69
5. https://lemonlemon.tistory.com/122
6. https://inyongs.tistory.com/38
7. https://inyongs.tistory.com/39
8. https://inyongs.tistory.com/44
9. https://inyongs.tistory.com/48
10. https://joooootopia.tistory.com/5
11. https://snoop-study.tistory.com/60
12. https://ddongwon.tistory.com/70
13. https://dkswnkk.tistory.com/485
14. https://dkswnkk.tistory.com/486
15. ['Protocol Layers and the OSI Model', Chapter 2 TCP/IP (Overview), "System Administration Guide: IP Services", Oracle](https://docs.oracle.com/cd/E19683-01/806-4075/806-4075.pdf)
16. http://wiki.hash.kr/index.php/OSI_7_%EA%B3%84%EC%B8%B5
17. https://depletionregion.tistory.com/83
18. https://dkswnkk.tistory.com/m/492
19. https://velog.io/@redgem92/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-%EB%8D%B0%EC%9D%B4%ED%84%B0-%EB%A7%81%ED%81%AC-%EA%B3%84%EC%B8%B5Data-Link-Layer-1
