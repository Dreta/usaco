# USACO 2024 February Contest, Silver
# Problem 1. Target Practice II


def solveMin(needsPos, pos):
    pos.sort()
    def ok(minY):
        maxSlope = []
        for x, y in needsPos:
            maxSlope.append((y - minY) // x)
        maxSlope.sort()
        return all(a <= b for a, b in zip(pos, maxSlope))
    
    minY = min(y for x, y in needsPos)
    hi = minY
    lo = minY - pos[-1] * max(x for x, y in needsPos)

    while lo < hi:
        mid = (lo + hi + 1) // 2
        if ok(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo


def solveMax(needsNeg, neg):
    return -solveMin([(x, -y) for x, y in needsNeg], [-x for x in neg])


def task():
    N, x1 = map(int, input().split())
    left = []
    needsNeg = []
    needsPos = []
    for _ in range(N):
        y1, y2, x2 = map(int, input().split())
        left.append(y1)
        left.append(y2)
        needsNeg.append((x2, y2))
        needsPos.append((x2, y1))
    
    posSlopes = []
    negSlopes = []
    for slope in map(int, input().split()):
        if slope > 0:
            posSlopes.append(slope)
        else:
            negSlopes.append(slope)
    
    if len(posSlopes) < N or len(negSlopes) < N:
        print(-1)
        return
    left.sort()
    posSlopes.sort(reverse=True)
    negSlopes.sort()

    for point in left:
        if len(needsNeg) < len(negSlopes):
            needsNeg.append((x1, point))
        else:
            needsPos.append((x1, point))

    print(solveMax(needsNeg, negSlopes) - solveMin(needsPos, posSlopes))


t = int(input())
for _ in range(t):
    task()
