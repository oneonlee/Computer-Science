# -*- coding: utf-8 -*-
"""huffman_encoding.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1qUFYKUK3PrQphFCNxdN4Sbp6o0SumM7W
"""

from queue import PriorityQueue

class HuffNode:
    def __init__ (self, symbol, freq):
        self.symbol = symbol
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self,other): # '<' OperatorMethod
        return self.freq < other.freq # 객체의 freq를 비교

    def __gt__(self,other): # '>' OperatorMethod
        return self.freq > other.freq # 객체의 freq를 비교

    def postorder(self, code=""): # 출력하기 위해 postorder 사용
        if (self.left is not None):
            self.left.postorder(code + '0')
        if (self.right is not None):
            self.right.postorder(code + '1')
        if self.symbol != ' ':
            print(f"{self.symbol} {code}")

def huffman(n, PQ):
    for _ in range(n - 1):
        p = PQ.get()[1]
        q = PQ.get()[1]
        r = HuffNode(' ', p.freq + q.freq)
        r.left = p
        r.right = q
        PQ.put((r.freq, r))
    return PQ.get()[1]

texts1 = ["X", "A", "B", "C", "D", "E", "F"]
freqs1 = [27, 15, 12, 9, 5, 10, 11]

PQ1 = PriorityQueue()

for i in range(len(texts1)):
    node = HuffNode(texts1[i], freqs1[i])
    PQ1.put((node.freq, node))

ex1 = huffman(len(texts1), PQ1)
ex1.postorder()

texts2 = ["LDG", "ABC", "ABCC", "AB", "A", "B", "BABA"]
freqs2 = [27, 12, 7, 19, 35, 40, 15]

PQ2 = PriorityQueue()

for i in range(len(texts2)):
    node = HuffNode(texts2[i], freqs2[i])
    PQ2.put((node.freq, node))

ex2 = huffman(len(texts2), PQ2)
ex2.postorder()