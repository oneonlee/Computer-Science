# -*- coding: utf-8 -*-
"""Levenshtein Distance.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1H1yotbcUxvDfo-u6l19sZ2Bg-G7xEFph
"""

# ICE3020 알고리즘 H/W #2 - 12181879 이동건

# * Levenshtein Distance를 구현하라.(총 100점)

import numpy as np # 빈 리스트를 만들기 위한 np.zeros() 함수 사용 목적
import math # 두 실수가 같은지 판단하기 위한 math.isclose() 함수 사용 목적

## (1) Levenshtein Distance를 구하는 알고리즘을 구현하고 Source=“GUMBO”, Target=“GAMBOL”를 이용하여 연산비용이 아래와 같을때 동작함을 보일 것. (30점)

def calculate_distance(source, target, cost):
    m = len(source)
    n = len(target)
    D = np.zeros((n+1, m+1))

    insertion_cost = cost[0]
    deletion_cost = cost[1]
    substitution_cost = cost[2]

    for i in range(1, n+1):
        D[i][0] = D[i-1][0] + insertion_cost(target[i-1])
    for j in range(1, m+1):
        D[0][j] = D[0][j-1] + deletion_cost(source[j-1])
    for i in range(1, n+1):
        for j in range(1, m+1):
            D[i][j] = min(D[i][j-1] + deletion_cost(source[j-1]),
                          D[i-1][j] + insertion_cost(target[i-1]),
                          D[i-1][j-1] + substitution_cost(source[j-1], target[i-1]))

    # 부동소수점 오차를 해결하기 위해 round() 함수를 사용하여 반올림하여 반환
    return round(D[n][m], 2)

source = "GUMBO"
target = "GAMBOL"

### (a) 삽입비용 = 삭제비용 = 1, 교환비용 = 0/1 일때

# 삭제, 삽입, 교체에 드는 비용을 람다 표현식으로 정의
insertion_cost_a = lambda x: 1
deletion_cost_a = lambda x: 1
substitution_cost_a = lambda x, y: 0 if x==y else 1

cost_a = [insertion_cost_a, deletion_cost_a, substitution_cost_a]

print("Levenshtein Distance : ", end="")
print(calculate_distance(source, target, cost_a))

### (b) 삽입비용 = 0.7, 삭제비용 = 0.5, 교환비용 = 0/0.3 일때

insertion_cost_b = lambda x: 0.7
deletion_cost_b = lambda x: 0.5
substitution_cost_b = lambda x, y: 0 if x==y else 0.3

cost_b = [insertion_cost_b, deletion_cost_b, substitution_cost_b]

print("Levenshtein Distance : ", end="")
print(calculate_distance(source, target, cost_b))

## (2) 위에서 작성한 알고리즘을 삽입, 삭제, 교환연산이 어떤 순서로 일어나는지 출력하도록 수정할 것, 아래 Data 1,2,3에 대한 연산순서를 출력할 것 (70점)
"""
(삽입비용 = 0.7, 삭제비용 = 0.5, 교환비용 = 0/0.3)

Source=“GUMBO”, Target=“GAMBOL”의 경우 출력 예)
교환연산 0.3, 삽입연산 0.7 : Levenshtein Distance = 1
"""

def updated_calculate_distance(source, target, cost):
    # calculate_distance() 함수와 동일
    m = len(source)
    n = len(target)
    D = np.zeros((n+1, m+1))

    insertion_cost = cost[0]
    deletion_cost = cost[1]
    substitution_cost = cost[2]

    for i in range(1, n+1):
        D[i][0] = D[i-1][0] + insertion_cost(target[i-1])
    for j in range(1, m+1):
        D[0][j] = D[0][j-1] + deletion_cost(source[j-1])
    for i in range(1, n+1):
        for j in range(1, m+1):
            D[i][j] = min(D[i][j-1] + deletion_cost(source[j-1]),
                          D[i-1][j] + insertion_cost(target[i-1]),
                          D[i-1][j-1] + substitution_cost(source[j-1], target[i-1]))

    # 연산이 어떤 순서로 일어나는지 출력하기 위해 추가한 부분
    order_list = []  # 어떤 연산이 일어났는지 역순으로 담는 리스트
    # 행렬의 마지막(가장 오른쪽 아래)에서 시작해 처음(왼쪽 위)으로 감
    i = n
    j = m
    cur = D[i][j]
    while (cur > 0):  # cur이 0이 되기 전까지, 즉 처음(왼쪽 위)에 도착할 때까지
        cur = D[i][j]

        # 파이썬에서 두 실수가 같은지 판단할 때, 부동 소수점 오차를 피하기 위해서 math.isclose를 사용해야 함
        if math.isclose(cur - D[i-1][j-1], substitution_cost(source[j-1], target[i-1])):
            if source[j-1] == target[i-1]:  # 글자가 같을 때는 아무 변화 없음
                if i > 0:
                    i = i-1
                if j > 0:
                    j = j-1
                continue

            # print("Change", source[j-1], "to", target[i-1])
            order_list.append(
                f"교환비용 {substitution_cost(source[j-1], target[i-1])}")

            # i, j가 0 초과일 때만 빼줌 (i[-1]처럼 넘어가는 것을 방지)
            if i > 0:
                i = i-1
            if j > 0:
                j = j-1

        elif math.isclose(cur - D[i][j-1], deletion_cost(source[j-1])):
            # print("Delete", source[j-1])
            order_list.append(f"삭제비용 {deletion_cost(source[j-1])}")

            if j > 0:
                j = j-1

        elif math.isclose(cur - D[i-1][j], insertion_cost(target[i-1])):
            # print("Insert", target[i-1])
            order_list.append(f"삽입비용 {insertion_cost(target[i-1])}")

            if i > 0:
                i = i-1

        else:
            if i > 0:
                i = i-1
            if j > 0:
                j = j-1

    order_list.reverse()  # 역순으로 append 해준 연산 순서를 원래대로 뒤집어줌
    for calculation in order_list:
        print(calculation)

    # 부동소수점 오차를 해결하기 위해 round() 함수를 사용하여 반올림하여 출력
    print(f": Levenshtein Distance = {round(D[n][m], 2)}")
    # return round(D[n][m], 2)

### Data 1) Source = Levenshtein, Target = Meilenstein

source_1 = "Levenshtein" 
target_1 = "Meilenstein"

updated_calculate_distance(source_1, target_1, cost_b)

### Data 2) Source = TACTG, Target = CATGACTG

source_2 = "TACTG"
target_2 = "CATGACTG"

updated_calculate_distance(source_2, target_2, cost_b)

### Data 3) Source = 데이타마이닝, Target = 데이터베이스설계

source_3 = "데이타마이닝"
target_3 = "데이터베이스설계"

updated_calculate_distance(source_3, target_3, cost_b)
