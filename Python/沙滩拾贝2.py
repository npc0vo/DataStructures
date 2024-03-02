n,m = map(int,input().split())
mylist= [int(x) for x in input().split()]
memo={}
def shell(n,m,mylist):
    max=0
    if len(mylist)<=1:
        return mylist[0]
    elif mylist in memo.keys:
        return memo[mylist]
    else:
        
           
            

# print(shell(n,m,mylist))

    