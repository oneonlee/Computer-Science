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

# References
1. 인공지능 응용 (ICE4104), 인하대학교 정보통신공학과 홍성은 교수님
2. [uni1023.log - 배치 사이즈(batch size), 에포크(epoch), 반복(iteration)의 차이는?](https://velog.io/@uni1023/%EB%B0%B0%EC%B9%98-%EC%82%AC%EC%9D%B4%EC%A6%88batch-size-%EC%97%90%ED%8F%AC%ED%81%ACepoch-%EB%B0%98%EB%B3%B5iteration%EC%9D%98-%EC%B0%A8%EC%9D%B4%EB%8A%94)