def shellSort(alist):
    sublistcount=len(alist)//2
    while sublistcount >0:
        #子列表排序
        for startposition in range(sublistcount):
            gapInsertionSort(alist,startposition,sublistcount)
        
        print("After increments of size",sublistcount,"The list is",alist)

        sublistcount = sublistcount //2
    return alist


def gapInsertionSort(alist,start,gap):
    for i in range(start+gap,len(alist),gap):
        currentvalue=alist[i]
        position=i
        while position >= gap and alist[position-gap]>currentvalue:
            alist[position]=alist[position-gap]
            position=position-gap
        alist[position]=currentvalue
list=[5,2,6,7,33,0]
print(shellSort(list))
#实际上就是改良版的选择排序
#把相对无序的逐渐接近有序，然后一次插入排序，只需要改动几次就行了
#算法复杂度是O(n**3/2)
