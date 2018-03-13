import numpy as np


def check(t_diff, x_diff, y_diff):
    l1 = abs(x_diff) + abs(y_diff)
    if l1 > t_diff:
        return False
    elif (t_diff - l1) % 2 == 1:
        return False
    else:
        return True

N = int(input())
t = np.zeros(N+1,)
x = np.zeros(N+1,)
y = np.zeros(N+1,)
for i in range(N+1):
    if i != 0:
        t[i], x[i], y[i] = tuple(map(int, input().split()))

for j in range(N):
    t_diff = t[j+1] - t[j]
    x_diff = x[j+1] - x[j]
    y_diff = y[j+1] - y[j]
    if not check(t_diff, x_diff, y_diff):
        print("No")
        exit()

print("Yes")