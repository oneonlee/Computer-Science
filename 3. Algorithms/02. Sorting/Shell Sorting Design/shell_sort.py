import numpy as np
import time
import matplotlib.pyplot as plt


def shell_sort(arr, N):
    h = 1
    while h < len(arr):
        h = 3*h + 1
    h = h//3

    while h > 0:
        for i in range(h, N):
            v = arr[i]
            j = i
            while j >= h and arr[j-h] > v:
                arr[j] = arr[j-h]
                j = j - h
            arr[j] = v
        h = h//3

    return arr


def check_sort(arr, N):
    sorted = True

    for i in range(N-1):
        if arr[i] > arr[i+1]:
            sorted = False
        if sorted == False:
            break

    if sorted == True:
        print("정렬 완료.")
    else:
        print("정렬 오류!!")
        print(arr)


time_list = []
N_list = [100000, 500000, 1000000, 5000000, 10000000]
for N in N_list:
    arr = np.random.randint(low=-N, high=N, size=N)  # 길이가 N개인 임의의 리스트를 생성
    start = time.time()
    shell_sort(arr, N)
    time_list.append(round(time.time() - start, 2))
    print(f"증가식 : 3h + 1, 감소식 : h/3, 쉘 정렬 시간 (N = {N}) : {time_list[-1]} sec")
    check_sort(arr, N)
