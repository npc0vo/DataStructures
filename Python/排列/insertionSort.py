list=[5,2,6,7,33,0]
def insertionSort(list):
    for i in range(1,len(list)):
        for j in range(i):
            if list[i]<list[j]:
                temp=list[i]
                for k in range(i,j-1,-1):
                    list[k]=list[k-1]
                list[j]=temp
                break
    return list
print(insertionSort(list))
def insertionSort(list):
    for index in range(1,len(list)):
        currentValue=list[index]
        position=index

        while position > 0 and list[position-1]>currentValue:
            list[position]=list[position-1]
            position=position-1
        list[position]=currentValue
    return list


                