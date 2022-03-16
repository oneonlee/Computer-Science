import time
import numpy as np


def matrixmult(a, b, c, n):
    start = time.time()

    temp = (np.zeros((a.shape)))
    res = (np.zeros((a.shape)))

    for i in range(n):
        for j in range(n):
            for k in range(n):
                temp[i][j] += b[i][k]*c[k][j]

    for i in range(n):
        for j in range(n):
            for k in range(n):
                res[i][j] += a[i][k]*temp[k][j]

    print("n^3(Cubic complexity) 소요 시간 =", time.time() - start, "sec")
    return res


for num in [10, 50, 100, 150, 200]:
    print("\nn :", num)

    mat1 = np.array([[i for i in range(num)] for j in range(num)])
    mat2 = np.array([[i for i in range(num)] for j in range(num)])
    mat3 = np.array([[i for i in range(num)] for j in range(num)])

    matrixmult(mat1, mat2, mat3, num)
