def selectionSort(list):
    for i in range(len(list)-1):
        min=i
        for j in range(i+1,len(list)):
            if list[j]<list[min]:
                min=j
        list[i],list[min]=list[min],list[i]
    return list
list=[5,2,6,7,33,0]
print(selectionSort(list))
#相当于冒泡排序的改进版，没有那么多交换了

