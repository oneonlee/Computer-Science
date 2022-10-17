# Transport Layer

- [Transport Layer services](#1-transport-layer-services)
- [Multiplexing, Demultiplexing](#2-multiplexing-demultiplexing)
- [Principles of RDT](#3-principles-of-rdtreliable-data-transfer)
- [Pipelined Protocols](#4-pipelined-protocols)

## 1. Transport Layer services

### Transport Layer의 역할

- 1. Source부터 Destination까지 패킷이 제대로 전송될 수 있도록 한다.
- 2. Application Layer에서 만든 데이터를 일정한 크기로 자른다.

### Transport Layer 프로토콜의 종류

세부적으로 들어가면 Transport Layer에도 여러가지 프로토콜들이 존재하지만, 대표적으로 두가지 프로토콜이 있다.

#### TCP (Transmission Control Protocol) for loss-sensitive application

- **reliable transport**
  - 전송 프로세스와 수신 프로세스 간의 안정적인 전송이 가능하다.
- **in-order delivery**
  - 데이터를 순서대로 전송한다.
- **connection-oriented (연결 지향)**, connection setup : 데이터를 보내기 전에 상대방의 상태를 확인하고, 클라이언트와 서버 간에 설정(setup)을 요구한다.
  - 여기서 말하는 설정(setup)이란?
    - 송신자/수신자에 buffer 할당
    - buffer & window size 설정 등
- flow control
  - 라우터와 받는 수신자의 상황을 봐서, 송신자 측 버퍼가 넘치치 않도록 보내는 패킷 양을 조절한다.
- **congestion control**
  - 각 TCP 연결이 네트워크 대역폭을 공평하게 공유할 수 있게끔 제어한다.
- Delay나 Bandwidth를 건드리지는 못한다.
- timing, minimum throughput guarantee, security 등의 기능은 제공하지 않는다.

#### UDP (User Datagram Protocol) for delay-sensitive application

- **unreliable data transfer**
- 패킷을 어떤 수신자의 어떤 서비스가 받아야 하는지(IP 주소, Port 번호), 패킷이 중간에 망가지지는 않았는지만 처리한다.
- UDP는 TCP에서 제공하는 것을 하나도 제공하지 않는다.
  - reliability, connection setup, flow control, congestion control, timing, minimum throughput guarantee, security 등을 **제공하지 않는다.**
- 정말 아무것도 안 하는 것 같은데 필요한 이유가 무엇일까?
  - UDP는 포트 번호에 따라 전달하는 역할을 한다.
  - UDP는 신뢰성을 보장하지는 않지만, TCP에 비하여 빠른 전송 속도를 제공한다.
  - UDP는 비연결을 지향하기 때문에 데이터를 재전송할 필요도 없고, 흐름 제어나 에러 체크도 항상 필요로 하지 않는다.

## 2. Multiplexing, Demultiplexing

애플리케이션들이 Transport Layer의 프로토콜을 이용하기 위해서는 프로세스마다 Socket을 이용해야 한다.

하지만, 컴퓨터에는 여러 개의 앱들이 돌아가고, 각각의 앱들은 하나 이상의 Socket을 생성할 수 있다.
따라서 Transport layer 입장에서는 여러개의 Socket에서 데이터들이 쏟아지는 형태가 된다.

여러 애플리케이션의 Socket들이 데이터를 송/수신하므로 필요한 개념이 바로 Multiplexing과 Demultiplexing이다.

여러 소켓에서 나온 데이터를 전송할때는 Multiplexing을, 받은 패킷을 적절한 소켓으로 보내줄때는 Demultiplexing을 적용한다.

### Multiplexing

여러 애플리케이션의 Socket들로부터 들어오는 데이터를 수집하여, 패킷으로 만들고 하위 계층으로 전송하는 것.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fk.kakaocdn.net%2Fdn%2F5pC0M%2FbtqVFBFjjhG%2FOKHjhKxCUplbHtDeGirJTK%2Fimg.png)

### Demultiplexing

하위 계층로부터 수신된 패킷을 정확한 Socket으로 전송하여 올바른 애플리케이션에게 전송하는 것.

이때 정확한 애플리케이션의 Socket으로 전달해주기 위해 포트 번호(Port Number)가 사용된다.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fk.kakaocdn.net%2Fdn%2Fb4daRi%2FbtqVIb7pDsM%2FRAZic4YT5w6sBXrXB4Vtak%2Fimg.png)

## 3. Principles of RDT(Reliable Data Transfer)

### Reliable Data Transfer

신뢰성 있는 데이터 교환(이하 RDT)은 한마디로 "송/수신하는 데이터가 오류없이 온전히 전송되는 것" 이다.

Transport Layer 에서는 신뢰성 있는 데이터 교환을 하고 싶어하지만, 그 아래의 레이어에서는 신뢰성을 보장할 수 없기 때문에 신뢰성 있는 통신에 문제가 생길 수 있다.

이러한 상황 속에서 Transport Layer에서 적용 가능한 방식이 바로 "RDT 프로토콜"을 이용하는 것이다. 아래 그림을 살펴보자.

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fk.kakaocdn.net%2Fdn%2FcmShf8%2FbtqVQVQ5j8E%2F4oO5Tf8CHzPiGCKqxIUaQ0%2Fimg.png)

- 패킷 송신 (상위 계층 → Transport Layer → 하위 계층)
  - 상위 계층 → Transport Layer :
    - `rdt_send()` 시스템 콜을 호출하여 RDT 프로토콜로 전송
  - Transport Layer → 하위 계층 :
    - `udt_send()` 호출하여 패킷 전송
- 패킷 수신 (하위 계층 → Transport Layer → 상위 계층)
  - 하위 계층 → Transport Layer :
    - `rdt_rcv()` 시스템 콜을 호출하여 RDT 프로토콜로 전송
  - Transport Layer → 상위 계층 :
    - `deliver_data()` 호출하여 데이터 전송

### Design of RDT

앞서 살펴본 RDT를 FSM(유한 상태 장치)을 이용하여 설계할 수 있다.

#### RDT 1.0

- 가정
  - 네트워크의 모든 채널이 완벽하게 신뢰성 있다고 가정한다. (no bit errors, no loss of packets)
- 기능
  - 송신자는 보낼 데이터를 패킷으로 만들어 패킷을 보내고, <br>수신자는 패킷으로부터 데이터를 추출하여 전달한다.
- 특징
  - 데이터 손상이나 손실의 우려가 없는 네트워크에서 사용할 수 있는 모델이다.

#### RDT 2.0

- 가정
  - 패킷 손실은 없다고 가정한다.
- 개선된 기능
  - 기본 채널에서는 패킷의 bit errors 가 발생할 수 있으므로, bit errors 를 탐지하기 위해 ACK/NAK와 checksum을 도입한다.
    - acknowledgements (ACKs) : 수신자가 송신자에게 패킷이 정상적으로 수신했음을 알린다.
    - negative acknowledgements (NAKs) : 수신자가 송신자에게 패킷에 에러가 있다는 것을 알린다.
  - 에러를 탐지하여 만약 에러가 있다면, 상대방의 Transport Layer에 다시 패킷을 요청한다.
- 문제점
  - ACK/NAK가 손실될 경우, 송신자는 수신자에게 무슨 일이 일어났는지 모른다.
    - 송신자가 수신자에게 Packet을 또 보낼 경우, 수신자는 중복인지 모르고 애플리케이션에게 중복된 데이터를 전달하는 경우가 생길 수 있다.

#### RDT 2.1

- 개선된 기능
  - (1) Sequence Number 사용
    - handling duplicates : 수신자가 packet의 중복 수신 여부를 확인할 수 있다.
  - (2) Stop and Wait
    - 송신자가 하나의 packet을 보내고나면, 수신자의 응답을 기다린다.
- 문제점
  - sequence number를 사용한다면, NAK를 사용할 필요가 없어진다.

#### RDT 2.2

- 개선된 기능
  - NAK 기능 제거
    - NAK을 사용하지 않는다.
    - 대신, 가장 마지막으로 잘 받은 패킷에 대한 번호의 ACK를 보낸다.
- 문제점
  - 여전히 패킷 손실의 가능성이 남아있다.

#### RDT 3.0

- 가정
  - 채널에 패킷 에러와 패킷 손실의 발생 가능성이 있다.
- 개선된 기능
  - timer 사용
    - 송신자가 데이터를 전송하고 일정 시간을 기다린다. 만약 시간 내에 올바른 ACK가 안오면 재전송 한다.

##### RDT 3.0 송신자

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fk.kakaocdn.net%2Fdn%2FbcZnWQ%2FbtqVZRzLYgX%2Fdsjj3Cmk0l5q6k3i2edurk%2Fimg.png)

위 그림에서 검은색 글씨들은 올바르게 패킷들이 교환되었을 경우이다. 이 경우 호출된 함수를 정상적으로 수행하게 된다.

빨간색 글씨들은 패킷 전송 과정에서 무언가 문제가 발생한 것이다. 패킷이 손상되었거나(corrupt), 손실되었을 때(wrong ACK) 그냥 이를 무시한다. 그러면 결국 timeout이 발생해 재전송을 하게 된다.

##### RDT 3.0 수신자

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fk.kakaocdn.net%2Fdn%2FJ9CX6%2FbtqVOrCE1hw%2FEhjt9A2FudkKDXefJJMpZ1%2Fimg.png)

위 그림에서 검은색 글씨들은 올바르게 패킷들이 교환되었을 경우이다. 이 경우 호출된 함수를 정상적으로 수행하게 된다.

빨간색 글씨들은 패킷 전송 과정에서 수신자가 보낸 ACK가 송신자에게 제대로 가지 않아 문제가 발생한 경우이다. 이 경우 다시 ACK을 만들어 송신자에게 재전송 해주어야 한다.

rdt 3.0 모델은 패킷이 유실된 경우, ACK가 유실된 경우, 유실되지는 않았지만 timeout이 발생한 경우 등 여러가지 변칙적인 상황을 모두 커버할 수 있어서 굉장히 완성도 높은 모델이라고 할 수 있다.

특히 패킷을 보내고 ACK가 올때까지 대기하는 양상을 보이는데, 이를 stop-and-wait Operation 이라고 한다. 이러한 특징 때문에 한편으로는 효율성이 낮다고 볼 수 있다.

## 4. Pipelined Protocols

앞서 서술하였듯이, [RDT 2.1](#rdt-21) 모델부터는 송신자가 하나의 packet을 보내고나면 수신자의 응답을 기다리는 "Stop and Wait" 방식을 사용한다고 하였다.

하지만 이 방법은 ACK가 올 때까지 송신자가 계속해서 놀고 있기 때문에 굉장히 비효율적인 방법이다.

따라서, 한번에 하나의 패킷만 보내는 것이 아니라 여러 패킷을 pipelining하여 처리하는 방식을 살펴볼 것이다. 대표적인 Pipelined Protocol으로는 GBN(Go-Back-N)과 SR(Selective Repeate) 방식이 있다.

### GBN(Go-back-N)

Go-back-N 방식은 수신자 측에서 받지 못한 패킷이 있다면, 송신자가 해당 패킷부터 순서대로 다시 재전송 하는 방식이다.

- (1) 수신자 측은 정상적으로 받지 못한 패킷이 있을 경우, 해당 패킷이 올 때까지 다른 패킷들을 받더라도, 받지 못한 패킷의 **직전 패킷에 대한 ACK**를 보낸다.
  - 수신자는 받은 ACK의 순서가 뒤섞이는 것을 허용하지 않는다.
    - 이러한 성질 때문에 cumulative ACK(연속적인 ACK)이라고도 한다.
  - 예를 들어 패킷 1,2,3,4,5를 전송했는데, 수신자 측에서 1,2,4,5를 받았다면, 수신자 측은 ACK 1,2,2,2를 보낸다.
    - 송신자 입장에서 ACK 1,2,3이 안오고 ACK 4만 오더라도 수신자가 패킷 1,2,3,4를 정상적으로 받았다는 것을 알 수 있다. (ACK가 오다가 손실된 경우)
- (2) 송신자는 전송한 패킷 중, ACK 되지 않은 가장 최신의 패킷에 대해 **하나의 타이머**를 계산한다.
  - 만약 해당 타이머가 만료될 때까지 ACK가 오지 않으면, window 내의 unack된 모든 패킷을 재전송한다.
  - 만약 해당 타이머가 만료되기 전에 ACK가 온다면, 다음 ACK 되지 않은 가장 최신의 패킷에 대해 타이머를 계산한다.
- (3) 구조가 간단하고 구현이 단순하며, 따로 패킷을 보관할 버퍼가 필요 없다.
  - 올바른 패킷이 오면 삼키고, 틀린 패킷이 오면 뱉는 구조이기 때문이다.
- (4) 송신자의 Window Size는 사용되는 sequence number보다 무조건 커야한다.
  - N = (2^k)-1
  - 만약 Window size가 같거나 작으면, 수신자가 오해할 수 있는 상황이 생긴다. (ACK가 모두 소실된 경우)

### SR(Selective Repeat)

Selective Repeat 방식은 송신자 측에서 받은 각각의 패킷들에 대해 ACK을 보내는 방식이다.

- (1) 송신자 측은 ACK가 순서대로 오든 말든, 그냥 받은 패킷에 대한 ACK을 보낸다.
  - 예를 들어 패킷 1,2,3,4,5를 전송했는데 송신자 측에서 1,2,4,5가 왔다면, 송신자 측은 ACK 1,2,4,5를 보낸다.
- (2) 송신자는 ACK을 받지 못한 **모든** 패킷에 대해 **타이머를 각각 계산**한다.
  - 만약 각각의 타이머가 만료될 때까지 ACK가 안오면, 각각 패킷을 재전송한다.
- (3) 따로 받은 패킷을 보관할 버퍼가 필요하다.
  - 올바르지 않은 패킷이 와도 일단 저장해놓고, 나중에 부족한 부분이 채워지면 함께 삼키는 구조이기 때문이다.
- (4) 사용되는 sequence number는 송신자의 Window Size와 송신자의 Widow Size 크기의 합보다 무조건 크거나 같야한다.
  - Max allowable window size N을 (2^k)-1이 아니라, (2^k)/2 = 2^(k-1)로 해야 한다. (half the seq# space)
  - 만약 sequence number의 크기가 더 작다면, 송신자가 오해할 수 있는 상황이 생긴다.

### 시각화 자료

- [YouTube - "Go back N sliding window Protocol by Khurram Tanvir"](https://www.youtube.com/watch?v=9BuaeEjIeQI)
- [YouTube - "Go Back N demonstration"](https://www.youtube.com/watch?v=gaocB7unrqs)
- [YouTube - "Selective Repeat sliding Window Protocol by Khurram Tanvir"](https://www.youtube.com/watch?v=Cs8tR8A9jm8)

---

## Source

1. **Computer Networking: A Top Down Approach** 6th edition - Jim Kurose, Keith Ross Addison-Wesley March 2012
2. https://ddongwon.tistory.com/m/79
3. https://ddongwon.tistory.com/m/80
4. https://ddongwon.tistory.com/m/81
5. https://m.blog.naver.com/mayooyos/220987008864
