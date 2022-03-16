import time

def fib(n):
    if n == 1 or n == 2:
        return 1
    
    return fib(n-2) + fib(n-1)

for num in [10, 20, 30, 40]:
    print("\nn :", num)
    start = time.time()
    fib(num)
    print("2^n (Exponential complexity) 소요 시간 =", time.time() - start, "sec")