import math
import sys
sys.setrecursionlimit(10000)


def modpw(x,n,m):
    x = int(x)
    n = int(n)
    m = int(m)
    if n == 0:
        return 1%m
    u = modpw(x,n//2,m)
    u = (u*u)%m
    if n%2 == 1:
        u = (u*x)%m
    return u


n,p,k = map(int,input().split())

anspl = 0
ansmin = 0
ans = 0

q = pow(10,k)

for i in range(1,n+1):
    if (n - i)%2 == 0:
        anspl += modpw(i%q,p,q)
    else:
        ansmin += modpw(i%q,p,q)

ans = (anspl - ansmin)%q

print(ans)