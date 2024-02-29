def mergeSort(alist):
    #设置递归终止条件
    if len(alist)>1:
        mid=len(alist)//2
        lefthalf=alist[:mid]
        righthalf=alist[mid:]
        mergeSort(lefthalf)
        mergeSort(righthalf)
        i=j=k=0

        #把归并到一起，拉链式交错
        while i<len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i+=1
            else:
                alist[k]=righthalf[j]
                j+=1
            k+=1
        #如果左部分有剩余
        while i<len(lefthalf):
            alist[k]=lefthalf[i]
            i+=1
            k+=1
        
        while j<len(righthalf):
            alist[k]=righthalf[j]
            j+=1
            k+=1
        print("Merging",alist)
list=[5,2,6,7,33,0]
mergeSort(list)

