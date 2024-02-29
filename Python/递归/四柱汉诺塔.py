from functools import lru_cache
@lru_cache(maxsize=128)


def hanoi4(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    elif n==2:
        return 3
    else:
        H=[]
        for x in range(1,n):
            H.append(2*hanoi4(x)+2**(n-x)-1)
        return min(H)
n=int(input())      
print(hanoi4(n))
print()
# 优化版，通过缓存避免进行了许多重复计算
h4cache=[None for x in range(n+1)]
def hanoi4_(n):
    if h4cache[n]:
        return h4cache[n]
    if n==0:
        h4cache[n]=0
    elif n==1:
        h4cache[n]=1
    elif n==2:
        h4cache[n]=3
    else:
        H=[]
        for x in range(1,n):
            H.append(2*hanoi4_(x)+2**(n-x)-1)
        h4cache[n]=min(H)
    return h4cache[n]
print(hanoi4_(n))
