n=int(input())
cache={0:1,1:1,2:2,3:4,4:8}
#递归版本
def total(n):
    if n<=4:
        return cache[n]
    elif n in cache:
        return cache[n]
    else:
        cache[n]=total(n-1)+total(n-2)+total(n-3)+total(n-4)
        return cache[n]
#迭代版本
def total1(n):
    if n<=4:
        return cache[n]
    else:
        for i in range(5,n+1):
            cache[i]=cache[i-1]+cache[i-2]+cache[i-3]+cache[i-4]
print(total(n))
