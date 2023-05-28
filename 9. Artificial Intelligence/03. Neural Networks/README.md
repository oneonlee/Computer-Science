# Neural Networks

## Curse of dimensionality (차원의 저주)

![curse_of_dimensionality](img/curse_of_dimensionality.jpg)

1. 차원이 늘어나면, 샘플 데이터의 수도 같이 늘어나야 한다.
2. 차원이 늘어나는데 샘플 데이터 수가 늘어나지 낳으면, 오히려 모델이 학습에 실패할 확률이 늘어난다.

### 차원 수에 따른 모델의 성능 그래프
샘플 데이터의 수는 고정하고, 차원을 늘렸을 때의 모델 성능 그래프

![dimensionality-performance](img/dimensionality-performance.PNG)

## Dimensionality Reduction

- 목적
    1. 차원을 축소함으로써, curse of dimensionality를 줄일 수 있다.
    2. Visualize를 할 수 있다.

![dimensionality-reduction](img/dimensionality-reduction.PNG)

## Dimensionality Expansion

- 목적
    - 차원을 적당히 늘려줌으로써, 데이터의 해석을 쉽게 할 수도 있음
     
![dimensionality-expansion](img/dimensionality-expansion.PNG)