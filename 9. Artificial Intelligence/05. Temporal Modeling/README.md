# Temporal Modeling

## Recurrent Neural Networks (RNN)

$$h_t = \tanh (W_{hh}h_{t-1} + W_{xh}x_{t})$$

<img src="https://lh3.googleusercontent.com/--wG97cZk_Cw/X7csFk4ULVI/AAAAAAAAOdc/wRjtbBislMI7xF0TUxOhbk3AyPKe9YOsACLcBGAsYHQ/w443-h180/image.png" />

### Backpropagation Through Time (BPTT)
[기존의 신경망 구조](../03.%20Neural%20Networks/)에서는 backpropagation 알고리즘을 이용한다. RNN에서는 이를 살짝 변형시킨 버전인 Backpropagation Through Time (BPTT) 을 사용하는데, 그 이유는 각 파라미터들이 네트워크의 매 시간 스텝마다 공유되기 때문이다. 즉, 각 시간 스텝의 출력단에서의 gradient는 현재 시간 스텝에서의 계산에만 의존하는 것이 아니라 이전 시간 스텝에도 의존한다.

### RNN tradeoffs
- RNN Advantages
    - 어떤 길이의 입력이라도 처리할 수 있다.
    - 긴 길이의 입력이 들어와도, 모델의 크기가 커지지 않는다.
    - 이론적으로, step t에 대한 계산은, 이전 단계의 정보를 포함한다.
- RNN Disadvantages
    - Recurrent 연산이 느리다.
    - 현실적으로, 오래 전의 step에서의 정보에 접근하기 어렵다.
    - [기울기 소실 (Vanashing Gradient)](https://wikidocs.net/61375)
        - 역전파 과정에서 입력층으로 갈수록 기울기가 점차 작아지는 현상. 
        - 입력층에 가까운 층들에서 가중치들이 업데이트가 제대로 되지 않으면 최적의 모델을 찾을 수 없게 된다.
        - LSTM을 사용하면, 기울기 소실을 막을 수 있다.
    - [기울기 폭주 (Exploding Gradient)](https://wikidocs.net/61375)
        - Gradient Clipping을 사용하면, 기울기 폭주를 막을 수 있다.
    
## Long Short-Term Memory (LSTM)

<img src="https://velog.velcdn.com/images%2Fyuns_u%2Fpost%2F4ef2c3a5-832f-41be-ade8-5f4c76d13fd1%2Fimage.png" />

- LSTM의 사용 이유
    - RNN은 데이터의 장기 의존성(long-term dependency)을 학습하는 데 어려움을 겪지만, LSTM은 더 긴 long-term 시퀀스를 처리할 수 있도록 만들어졌다.
    - LSTM은 Memory Cell과 Gate를 사용하여 장기 및 단기 Hidden State를 통과한다.
    - Cell state를 도입하면서 gradient flow가 방해 받지 않게 하며, gradient가 잘 흘러가지 않는 것을 막아준다.

### LSTM의 각 Gate들의 역할

#### 1. Forget Gate ($f_{t}$)

<img src="https://imghub.insilicogen.com/media/photos/LSTM3-focus-f.png"/>

- 과거 정보를 얼마만큼 유지할 것인가?
- Forget Gate는 cell state에서 sigmoid($\sigma{}$) layer를 거쳐 이전 hidden state를 얼마나 기억할지 정한다.

#### 2. Input Gate ($i_{t}$)

<img src="https://imghub.insilicogen.com/media/photos/LSTM3-focus-i.png"/>

- 새로 입력된 정보는 얼마만큼 활용할 것인가?
- Input Gate는 새로 입력된 정보 중 어떤 것을 cell state에 저장할 것인지를 정한다. 먼저 sigmoid($\sigma{}$) layer를 거처 어떤 값을 업데이트 할 것인지를 정한 후, $\tanh$ layer에서 새로운 후보 Vector를 만든다.
    - 활성화함수로써 sigmoid를 쓰지 않고, $\tanh$를 쓰는 이유는 [여기](https://wiserloner.tistory.com/1110) 참고

#### 3. Output Gate ($o_{t}$)
    
<img src="https://imghub.insilicogen.com/media/photos/LSTM3-focus-o.png"/>

- 두 정보를 계산하여 나온 출력 정보를 얼마만큼 넘겨줄 것인가?
- Output Gate는 어떤 정보를 output으로 내보낼지 정한다. 먼저 sigmoid($\sigma{}$) layer에 input data를 넣어 output 정보를 정한 후 Cell state를 \tanh layer에 넣어 sigmoid($\sigma{}$) layer의 output과 곱하여 output으로 내보낸다.

# References
1. 인공지능 응용 (ICE4104), 인하대학교 정보통신공학과 홍성은 교수님
2. [[머신러닝/딥러닝] 10-1. Recurrent Neural Network(RNN)](https://sonsnotation.blogspot.com/2020/11/10-recurrent-neural-networkrnn.html)
3. [RNN Tutorial Part 2 - Python, NumPy와 Theano로 RNN 구현하기](http://aikorea.org/blog/rnn-tutorial-2/)
4. [Neural Network Notes](https://rstudio-pubs-static.s3.amazonaws.com/840976_c6e818a01f2c4b139e85e8074af60805.html)
5. [LSTM(Long-Short Term Memory)과 GRU(gated Recurrent Unit)(코드 추가해야함)](https://velog.io/@yuns_u/LSTMLong-Short-Term-Memory%EA%B3%BC-GRUgated-Recurrent-Unit)
6. [07-07 기울기 소실(Gradient Vanishing)과 폭주(Exploding) - 딥 러닝을 이용한 자연어 처리 입문](https://wikidocs.net/61375)
7. [LSTM - 인코덤, 생물정보 전문위키](http://www.incodom.kr/LSTM#h_a963932a2464f3866c7891e38db0e30b)
8. [[딥러닝] LSTM 쉽게 이해하기 - YouTube](https://www.youtube.com/watch?v=bX6GLbpw-A4)
9. [Loner의 학습노트 :: LSTM 개인정리](https://wiserloner.tistory.com/1110)
