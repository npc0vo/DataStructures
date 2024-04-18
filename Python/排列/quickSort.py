def quickSort(alist):
    quickSortHelper(alist,0,len(alist)-1)


def quickSortHelper(alist,first,last):
    if first < last:
        splitpoint=partition(alist,first,last)
        quickSortHelper(alist,first,splitpoint-1)
        quickSortHelper(alist,splitpoint+1,last)
def partition(alist,first,last):
    pivotvalue=alist[first]
    
    leftmark=first+1
    rightmark=last

    done=False
    while not done:

        while leftmark <= rightmark and\
        alist[leftmark]<=pivotvalue:
            leftmark+=1
        
        while alist[rightmark]>=pivotvalue and\
        rightmark >=leftmark:
            rightmark-=1
        if rightmark < leftmark:
            done=True  #左右标记相逢就结束
        else:
            alist[leftmark],alist[rightmark]=alist[rightmark],alist[leftmark]
    
    alist[first],alist[rightmark]=alist[rightmark],alist[first]
    return rightmark
#算法流程：
#以第一个为基准值，左边界为first+1 右边界为last
#左指针向右移动，遇到比基准值大的就停止  右指针向左移动，遇到比基准值小的就停下
#交换左右指针的值,然后继续移动，继续交换知道两个指针交错停止
#此时右指针指向的值小于基准值，左指针指向的值大于基准值
#交换基准值和右指针指向的值,此时右指针左边的值都小于基准值
#划分成两部分，这两部分重复上面的流程
#继续划分
#最小的数据项只有3个，直接就排好了

#快速排序过程分为两部分:分裂好移动
#若分裂总能把数据表分为相等的两部分 复杂度就是logn
#而移动需要每项都与中值进行对比 复杂度就是n
# 中和起来是nlogn
#算法过程不需要额外的存储空间
#如何中值的分裂点过于偏离中部，极端情况下有一部分没数据，时间复杂度就退化到O(n**2)








alist=[54,26,44,5,532,567,134]
quickSort(alist)
print(alist)
