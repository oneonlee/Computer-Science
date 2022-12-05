# Wireless and Mobile Networks

## wireless link

wireless link란 모바일과 기지국 간의 link를 말한다.

기지국 하나가 커버하는 영역을 cell이라고 한다. 형용사로 표현하면 cellular라고 한다. 그래서 cullular network라고 하면 이동통신 네트워크를 가리키게 된 것이다. 이 하나의 cell 내에 통신사에 가입된 사용자가 동시에 접속한다면 multiple access protocol을 쓴다. 처음에는 랜덤하게 ALOHA 방식으로 작은 데이터를 보내고, 충돌이 나지 않으면 그 다음부터 기지국이 쓸 수 있는 리소스를 할당해주는 방식이었다.

그리고 data rate가 가변적이다. 과거의 2G 시절에는 대부분 전화라서 전송률이 고정이었다. 음성에서 데이터로 넘어오면서 각자 모바일이 처해있는 환경에 따라, 환경이 좋으면 전송률 높여주고 환경이 나쁘면 전송률을 낮춰준다. 게다가 동시에 사용하는 접속자의 수에 따라 나눠줘야 한다. 그래서 상황에 따라 속도가 낮기도 하고 높기도 하다. 말 그대로 패킷 스위칭의 컨셉이 셀룰라 망에 들어와 있는 것이다.

transmission distance도 가변적이다. 상황에 따라서 어떤 날은 데이터가 날아가는데 어떤 날은 데이터가 안 날아갈 수 있다. 무선이라는 게 기상환경 등 주변 환경에 따라 노이즈가 그때마다 다르다. 그래서 받을 수 있는 최대거리가 가변적이다.

## infrastructure mode

infrastructure mode란 기지국 통해서 통신하는 mode를 말한다.

handoff는 디바이스가 기지국을 바꾸는 것이다. 옛날 2G 시절에 전화하면서 이동하다보면 항상 끊기는 지점이 있었다. 큰 네트워크가 바뀌는 영역에서 그랬었다. 지금은 LTE나 5G에서는 handoff가 거의 해결되었다.

## ad hoc mode

기지국 없이 단말들이 스스로 네트워크를 구성하는 것이다. 스스로 망을 만들어서 통신하는 형태이다. 역사가 오래되었다.

e.g., 군용 P96K : 단말기가 라우터의 역할도 한다. 또한, 데이터 송수신 시 다익스트라 알고리즘처럼 최적의 경로를 찾고 송수신함

## Wireless links, characteristics

- wired link와 중요한 차이점
  - decreased signal strength
  - interference from other sources
  - multipath propagation
    - bit rate를 증가시키기 어려움

## IEEE 802.11 MAC Protocol: CSMA/CA

---

## References

1. **Computer Networking: A Top Down Approach** 6th edition - Jim Kurose, Keith Ross Addison-Wesley March 2012
