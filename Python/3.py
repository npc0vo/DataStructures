n=input()
def func(n):
    if len(n)<=1:
        return int(n)
    else:
        temp=0
        for i in n:
            temp+=int(i)
        return func(str(temp))    
print(func(n))