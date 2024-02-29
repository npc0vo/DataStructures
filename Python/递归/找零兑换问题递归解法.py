# from functools import lru_cache
# @lru_cache(maxsize=128)
import time
#实际上就是暴力枚举，重复计算比较多算的有点慢
def recMC(coinValueList,change):
    mincoins=change
    if change in coinValueList:
        return 1
    else:
        for i in [c for c in coinValueList if c < change]:
            numcoins = 1 + recMC(coinValueList,change-i)
            if numcoins < mincoins:
                mincoins=numcoins
        return mincoins
# print(recMC([1,5,10,25],63))

#递归解法优化  消除重复计算
#就是把算法中间过程的部分最优解记录下来
change=int(input())
KnownResult=[None for i in range(change+1)]
def recDC(coinValueList,change):
    mincoins=change
    if change in coinValueList:
        KnownResult[change]=1
        return 1
    elif KnownResult[change]:
        return KnownResult[change]
    else:
        for i in [c for c in coinValueList if c < change]:
            numcoins=1+recDC(coinValueList,change-i)
            if numcoins < mincoins:
                mincoins=numcoins
                KnownResult[change]=mincoins
        return mincoins
print(time.time())
print(recDC([1,5,10,25,21],change))
print(time.time())




