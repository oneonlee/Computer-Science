# Optimization

## Epoch vs Batch vs Iteration

- Epoch
    - 전체 데이터셋을 한 바퀴 순회하여 학습하는 것
- (Mini-)Batch
    - 전체 데이터셋을 여러 개의 작은 묶음으로 나누어 학습하는 방법
- Iteration / Step
    - 1-Epoch을 마치는데 필요한 Mini-Batch의 개수
        - 1-Epoch에서 Batch 단위로 학습을 완료한 것
    - 1-epoch를 마치는데 필요한 파라미터 업데이트 횟수
        - 각 Mini-Batch마다 파라미터 업데이터가 한 번 씩 진행됨

### Batch Size와 Learning Rate 정하기

> Baseline 모델의 Batch Size와 Learning Rate를 알고 있을 때, Batch Size를 늘리거나 줄인다면, Learning Rate는 어떻게 조절해야 할까?

- Baseline의 `batch_size = 128`, `learning_rate=0.001`이라고 가정
    - if `batch_size = 64`로 **1/2배** 한다면
        - `learning_rate=0.0005`로 똑같이 **1/2배** 해줌
    - if `batch_size = 256`로 **2배** 한다면
        - `learning_rate=0.002`로 똑같이 **2배** 해줌

## Gradient Descent

## Stochastic Gradient Descent
### Mini-batch SGD: Loop
1. **Sample a batch of data**
2. **Forward prop** it thriugh the graph(network), **get loss**
3. **Backprop** to calculate the gradients
4. **Update the parameters** using the gradient

### Momentum
- 장점
    1. weight 변수들에 대한 편미분 계수 값들의 차이가 클 때에도 빠르게 수렴할 수 있도록 도와준다.
    2. Saddle Point나 Local Minimum에서 빠져나오도록 도와준다.

## Learning Rate Scheduling

### Learning Rate Decay
- 필요성
    - 고정된 Learning Rate를 사용하는 경우, 모델이 Global Minimum Loss에 수렴하기 쉽지 않다. 따라서, 초기 학습 단계에서 큰 Learning Rate를 사용하여 Global Minimum Loss 주변에 빠르게 접근하고, 점차 Learning Rate를 줄여나가면서 Global Minimum Loss에 세부적으로 수렴하도록 사용한다.
- 동작 방식
    - 앞서 말한대로, Learning Rate Decay의 철학은 초기 학습 단계에서는 큰 Learning Rate를 사용하고, 학습이 진행됨에 따라 점차 Learning Rate를 줄여나가는 것이다. Learning Rate Decay의 알고리즘은 여러가지가 있으며, 대표적으로 사용되는 Cosine Annealing 기법은 Learning Rate가 Cosine 함수 그래프처럼 변한다. 이외에도 Learning Rate가 Exponential 함수의 개형처럼 변하는 ExponentialLR 기법과, 사용자가 지정한 Step 마다 일정하게 Learning Rate가 줄어드는 StepLR 기법 등이 있다.

### Warmup
- 필요성
    - 모델 학습 시, 초기 학습 단계부터 큰 Learning Rate를 사용하는 것은 학습의 불안정을 초래할 수 있다. 따라서, Warmup을 통해 작은 Learning Rate부터 학습을 시작해서 점차 늘려나가고, Warmup 이후에 고정된 Learning Rate를 사용하거나, Learning Rate Decay 기법을 사용한다.
- 동작 방식
    - Warmup은 모델의 초기 학습 단계에서 점차 Learning Rate를 늘려나가는 것이다. 앞서 말한대로, Warmup 이후에는 고정된 Learning Rate를 사용하거나, Learning Rate Decay 기법을 사용한다.

# References

1. 인공지능 응용 (ICE4104), 인하대학교 정보통신공학과 홍성은 교수님
2. [uni1023.log - 배치 사이즈(batch size), 에포크(epoch), 반복(iteration)의 차이는?](https://velog.io/@uni1023/%EB%B0%B0%EC%B9%98-%EC%82%AC%EC%9D%B4%EC%A6%88batch-size-%EC%97%90%ED%8F%AC%ED%81%ACepoch-%EB%B0%98%EB%B3%B5iteration%EC%9D%98-%EC%B0%A8%EC%9D%B4%EB%8A%94)
3. [[논문요약] Classification 학습방법 - Bag of Tricks(2018)](https://kmhana.tistory.com/25)
