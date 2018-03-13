a = int(input())
for i in range(1, 100000):
    if i % 2 == 0:
        a = a * i

print(a)