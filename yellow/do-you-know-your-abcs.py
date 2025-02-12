# USACO 2021 US Open, Silver
# Problem 2. Do You Know Your ABCs?

import itertools

def solve_linear_system(A, b):
    m = len(A)
    if m == 0:
        return []
    n = len(A[0])
    aug = [A[i][:] + [b[i][0]] for i in range(m)]
    
    pivot_row = 0
    pivot_positions = []

    for col in range(n):
        max_row = None
        max_val = 0.0
        for i in range(pivot_row, m):
            if abs(aug[i][col]) > max_val:
                max_val = abs(aug[i][col])
                max_row = i
        if max_row is None or abs(aug[max_row][col]) < 1e-12:
            continue

        aug[pivot_row], aug[max_row] = aug[max_row], aug[pivot_row]
        pivot_positions.append((pivot_row, col))
        
        for i in range(pivot_row + 1, m):
            factor = aug[i][col] / aug[pivot_row][col]
            for j in range(col, n + 1):
                aug[i][j] -= factor * aug[pivot_row][j]
        
        pivot_row += 1
        if pivot_row == m:
            break

    for i in range(pivot_row, m):
        if all(abs(aug[i][j]) < 1e-12 for j in range(n)) and abs(aug[i][n]) > 1e-12:
            return None

    x = [0] * n

    for row, col in reversed(pivot_positions):
        s = aug[row][n]
        for j in range(col + 1, n):
            s -= aug[row][j] * x[j]
        x[col] = s / aug[row][col]

    return [[xi] for xi in x]


def task():
    input()
    nums = list(map(int, input().split()))
    operations = {1: 'A', 2: 'B', 3: 'C', 4: 'A + B', 5: 'B + C', 6: 'A + C', 7: 'A + B + C'}

    results = set()
    for ops_perm in itertools.permutations(operations.keys(), len(nums)):
        mapping = dict(zip(nums, ops_perm))

        A = []
        b = []
        for number, operation in mapping.items():
            if operation == 1:
                A.append([1, 0, 0])
            elif operation == 2:
                A.append([0, 1, 0])
            elif operation == 3:
                A.append([0, 0, 1])
            elif operation == 4:
                A.append([1, 1, 0])
            elif operation == 5:
                A.append([0, 1, 1])
            elif operation == 6:
                A.append([1, 0, 1])
            elif operation == 7:
                A.append([1, 1, 1])
            b.append([number])
        answer = solve_linear_system(A, b)
        works = answer is not None

        this_answer = []
        if answer is not None:
            for a in answer:
                if a[0] < 1 or a[0] != int(a[0]):
                    works = False
                    break
                this_answer.append(int(a[0]))
        if works:
            results.add(tuple(sorted(this_answer)))

    print(len(results))


for _ in range(int(input())):
    task()
