## P vs. NP vs. NP-hard vs. NP-complete

- **P**
  - **다항시간 내에 풀 수 있는 문제**
  - 또는 다차시간 알고리즘을 찾은 문제
- **NP**
  - **다항시간 내에 답이 맞았는지 틀렸는지 확인해줄 수 있는 문제** (verification)
  - 또는 다루기 힘들다고 증명되지 않았고, 다차시간 알고리즘도 찾지 못한 문제
- [**NP-hard**](#np-hard)
  - 아무리 답을 추측해도 그 답이 맞았는지 틀렸는지 확인이 어려운 문제 (예 : 최적화 문제)
- [**NP-complete**](#np-complete)
  - [NP-hard](#np-hard)임과 동시에 NP인 문제, 즉 모든 NP 문제를 [Polynomial-Time Reduction (다항식 시간 변환)](#polynomial-time-reduction-다항식-시간-변환)시킨 문제가 다시 NP가 될 때, 그 문제를 'NP-complete 문제'라고 부른다.

## NP-hard

- NP-hard에 속하는 문제는?
  - 모든 [NP-complete](#np-complete)은 NP-hard문제이다.
- NP-hard에 속하지 않는 문제는?
  - 아직 모름. 어떤 문제가 NP-hard가 아니라고 증명하게 된다면 `P ≠ NP`임을 증명하게 되는 것.
- 다항시간 알고리즘을 발견한 문제는 NP-hard가 아닐지도 모름.
  - 다항시간 알고리즘이 있는 어떤 문제가 NP-hard임을 증명하면 `P = NP`임을 증명하게 되는 것.

<img width="822" src="https://user-images.githubusercontent.com/73745836/172292609-ef9d1ba5-6e8e-48a3-a5c9-dda3f566619c.png">

## NP-complete

### 최초의 NP-complete 문제

> **GSAT**

### 어떤 문제가 NP-complete인지 증명하기 위한 과정

만일,

- (1) 문제 B가 NP에 속하고
- (2) NP에 속해 있는 **모든 다른 문제** A에 대해 `A ≤ ₚB`이면 B는 NP-complet이다. (NP-complete의 정의)
  - (2) 또는 잘 알려진 NP-complete 문제 A에 대해 `A ≤ ₚB`이면 B는 NP-complet이다. (Cook의 정리)

#### Polynomial-Time Reduction (다항식 시간 변환)

- 문제 A의 사례 α를 문제 B의 사례 β로 바꾸되 아래 성질을 만족하면 polynomial-time reduction이라 하고, 이를 `α ≤ ₚβ` 로 표기한다
  - (1) 변환은 다항식 시간에 이루어진다
  - (2) 두 사례의 답은 일치한다
