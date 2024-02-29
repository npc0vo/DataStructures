'''
记录评发ratings,
和对应的糖果数cds
将小朋友的评分按照次序加入
第一个，无论多少分，只有1颗糖果；
后续的：
如果发数高王前一个
则比前面多1颗糖果；
如果分数与前一个相同，则给最低标准1颗糖果；
如果分数低于前一个，则给最低标准1颗糖果
..但是，如果前一个仅有1颗糖果，
...…就需要加1颗糖，并向前继续加，
直到评分不递增，或者糖果有多。
'''
def candy(ratings):
    cds=[1]*len(ratings) #糖果列表
    for i in range(1,len(ratings)):
        if ratings[i-1] < ratings[i]:
            cds[i]=cds[i-1]+1
        elif ratings[i-1]==ratings[i]:
            cds[i]=1
        else:
            cds[i]=1
            if cds[i-1]==1:
                for k in range(i-1,-1,-1):
                    cds[k]+=1
                    if k >0 and (ratings[k]>=ratings[k-1]\
                    or cds[k]<cds[k-1]):
                        break
    return sum(cds)