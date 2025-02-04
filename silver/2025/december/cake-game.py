# USACO 2024 December Contest, Silver
# Problem 1. Cake Game

T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    pre = [0]
    for x in a:
        pre.append(pre[-1] + x)
    minval = float('inf')
    for i in range(n - n // 2):
        minval = min(minval, pre[i + n // 2 + 1] - pre[i])
    print(minval, pre[-1] - minval)
