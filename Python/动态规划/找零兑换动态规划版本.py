def dpMakeChange(coinValueList,change,mincoins,coinsUsed):
    #从1到change逐个计算每个最优解:
    for cents in range(1,change+1):
        #初始化一个最大值
        coinCount=cents
        newcoin=1
        #减去每个硬币，向后查最优解数，比较得到当前的最优解数
        for j in [c for c in coinValueList if c <= cents]:
            if mincoins[cents-j]+1 < coinCount:
                coinCount=mincoins[cents-j]+1
                newcoin=j
        #获取当前最少硬币数，记录到表中
        mincoins[cents]=coinCount
        coinsUsed[cents]=newcoin
    printCoins(coinsUsed,change)
    return mincoins[change]
def printCoins(coinsUsed,change):
    coin=change
    while coin >0:
        print(coinsUsed[coin])
        coin-=coinsUsed[coin]
    print(coinsUsed)
        
print(dpMakeChange([1,5,10,21,25],63,[0]*64,[0]*64))

