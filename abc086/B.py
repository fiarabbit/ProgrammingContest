s = int("".join(list(input().split())))
for k in range(317):
    if k ** 2 == s:
        print("Yes")
        exit()
print("No")
