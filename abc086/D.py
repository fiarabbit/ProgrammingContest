import numpy as np

N, K = list(map(int, input().split()))
x = np.zeros(N, dtype=np.uint32)
y = np.zeros(N, dtype=np.uint32)
c = np.zeros(N, dtype=np.bool)

for i in range(N):
    s = input().split()
    x[i], y[i] = list(map(int, s[0:2]))
    c[i] = (s[2]=="W")

x_true = np.zeros(N, dtype=np.uint32)
y_true = np.zeros(N, dtype=np.uint32)
for i in range(N):
    if (x[i] // K) % 2 == 0:
        x_true[i] = int(x[i] % K)
        y_true[i] = int((y[i] + c[i] * K) % (2*K))
    else:
        x_true[i] = int(x[i] % K)
        y_true[i] = int((y[i] + c[i] * K + K) % (2*K))

counter = np.zeros((K, 2*K), dtype=np.uint32)
for i in range(len(y_true)):
    counter[x_true[i], y_true[i]] += 1

sum_counter = np.zeros((K, 2*K), dtype=np.uint32)
s = np.sum(counter)
for x_k in range(K):
    for y_k in range(2*K):
        if y_k < K:
            sum_counter[x_k, y_k] = counter[x_k:K, y_k:y_k+K].sum() + counter[0:x_k, 0:y_k].sum() + counter[0:x_k, y_k+K:2*K].sum()
        else:
            print(y_k)
            exit()
            sum_counter[x_k, y_k] = counter[0:x_k, y_k-K:y_k].sum() + counter[x_k:K, 0:y_k].sum() + counter[x_k:K, y_k+K:2*K].sum()

print(np.max(sum_counter.ravel()))
