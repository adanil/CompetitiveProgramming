def modpw(x,n):
    x = int(x)
    n = int(n)
    if n == 0:
        return 1
    u = modpw(x,n//2)
    u = (u*u)
    if n%2 == 1:
        u = (u*x)
    return u


def fac(n):
    if (n == 0):
        return 1
    else:
        ans = 1
        for i in range(2,n+1):
            ans *= i
        return ans


n,k = map(int,input().split())

sum = 0

for i in range(n+1):
    sum += modpw(fac(i),k)


str = str(sum)

i = len(str) - 1

while(str[i] == '0'):
    i -= 1

print(str[i])
