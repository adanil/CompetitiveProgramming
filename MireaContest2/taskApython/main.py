n = int(input())


real = list()
for i in range(n):
    s = input()
    real.append(s)
q = int(input())
for i in range(q):
    s = input()
    if s in real:
        print("YES")
    else:
        print("NO")