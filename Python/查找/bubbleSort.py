def bubbleSort(list):
    for passnum in range(len(list)-1,-1,-1):
        for i in range(passnum):
            if list[i] > list[i+1]:
                list[i],list[i+1]=list[i+1],list[i]
    return list
list=[1,3,9,2,4]
print(bubbleSort(list))
#比对次数为(n-1)(n-2)/2
#算法复杂度为O(n**2)


