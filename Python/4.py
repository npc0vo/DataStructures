n=int(input())
memo=[None for i in range(n+1)]
def func(n):
    if n==0:
        memo[0]=0
        return 0
    elif n==1:
        memo[1]=1
        return 1
    else:
        memo[n]=func(n//2)+func(n%2)
        return memo[n]

print(func(n))