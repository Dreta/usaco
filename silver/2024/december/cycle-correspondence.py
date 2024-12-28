# USACO 2023 December Contest, Silver
# Prolbem 2. Cycle Correspondence

N, K = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

outside = set(range(1, N + 1)) - set(a) - set(b)


def findMaxCycle(ca, cb):
    positions = {value: i for i, value in enumerate(ca)}
    results = [0] * K  # results[i] = number of cycles when we rotate cb by i
    for i, value in enumerate(cb):
        if value in positions:
            results[i - positions[value]] += 1
    return max(results)


print(max(findMaxCycle(a, b), findMaxCycle(a, b[::-1])) + len(outside))
