
# def dpSteal(itemList,weight,dpvalue,itemStolen):
#     dpvalue[2]=3
#     dpvalue[3]=4
#     dpvalue[4]=8
#     dpvalue[5]=8
#     dpvalue[9]=10
#     for i in range(2,weight+1):
#         valueCount=0
#         itemStolend=0
#         for j,k in itemList.items():
#             if j<i:
#                 dpvalue[i]=k+dpvalue[i-j]
#                 if valueCount < dpvalue[i]:
#                     valueCount=dpvalue[i]
#                     itemStolend=k
#         dpvalue[i]=valueCount
#     return dpvalue[weight]
# print(dpSteal({2:3,3:4,4:8,5:8,9:10},20,[0]*21,[0]*21))
# def dpSteal(itemList, weight, dpvalue, itemStolen):
#     for i in range(2, weight + 1):
#         valueCount = 0
#         d = 0

#         for j, k in itemList.items():
#             if j <= i:
#                 dpvalue[i] = k + dpvalue[i - j]  # 修正此行
#                 if valueCount < dpvalue[i]:
#                     valueCount = dpvalue[i]
#                     d=j
#         dpvalue[i] = valueCount
#         itemStolen[i]=d
#     printstolen(weight,itemStolen)
#     return dpvalue[weight]
# def printstolen(weight,itemStolen):
#     while weight >0:
#         print(itemStolen[weight])
#         weight-=itemStolen[weight]
        
# print(dpSteal({2: 3, 3: 4, 4: 8, 5: 8, 9: 10}, 20, [0] * 21, [0] * 21))
def dpSteal(itemList, weight, dpvalue, itemStolen):
    for i in range(1, weight + 1):  # Corrected the starting index
        valueCount = 0
        d = 0

        for j, k in itemList.items():
            if j <= i:
                current_value = k + dpvalue[i - j]
                if valueCount < current_value:
                    valueCount = current_value
                    d = j
        dpvalue[i] = valueCount
        itemStolen[i] = d

    printstolen(weight, itemStolen)
    return dpvalue[weight]

def printstolen(weight, itemStolen):
    while weight > 0:
        print(itemStolen[weight])
        weight -= itemStolen[weight]

print(dpSteal({2: 3, 3: 4, 4: 8, 5: 8, 9: 10}, 20, [0] * 21, [0] * 21))



#动态规划解法
#宝物的重量和价值
tr=[None,{'w':2,'v':3},{'w':3,'v':4},{'w':4,'v':8},{'w':5,'v':8},{'w':9,'v':10}]
#大盗最大承重
max_w=20
#初始化二维表格m[(i,w)]
#表示前i个宝物中,最大重量w的组合，所得到的最大价值
#当i什么都不取，或取w上限为0，价值均为0
m={(i,w):0 for i in range(len(tr))for w in range(max_w+1)}
#逐个填写二维表格:
for i in range(1,len(tr)):
    for w in range(1,max_w+1):
        if tr[i]['w']>w:
            m[(i,w)]=m[(i-1,w)]
        else:
            #不装第i个宝物，装第i个宝物，两种情况下的最大价值
            m[(i,w)]=max(m[(i-1,w)],m[(i-1,w-tr[i]['w'])]+tr[i]['v'])
print(m[(len(tr)-1,max_w)])





#递归解法
tr={(2,3),(3,4),(4,8),(5,8),(9,10)}
max_w=20
#记忆化表格m
m={}
def thief(tr,w):
    if tr==set() or w==0:
        m[tuple(tr),w]=0
        return 0
    elif(tuple(tr),w) in m:
        return m[(tuple(tr),w)]
    else:
        vmax=0
        for t in tr:
            if t[0] <= w:
                v=thief(tr-{t},w-t[0])+t[1]
                vmax=max(v,vmax)
        m[(tuple(tr),w)]=vmax
        return vmax
print(thief(tr,max_w))
