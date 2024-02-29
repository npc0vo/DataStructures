#迭代版
def binarySearch(alist,item):
    first=0
    last=len(alist)-1
    found=False
    while first <= last and not found:
        mid = (first + last) //2
        if item > alist[mid]:
            first=mid+1
        elif item < alist[mid]:
            last=mid-1
        elif alist[mid]==item:
            found=True
    return found
testlist=[0,1,2,3,4,5,6,7,8]
print(binarySearch(testlist,3))
print(binarySearch(testlist,13))
#递归版
def binarySearch2(alist,item):
    if len(alist)==0:
        return False
    else:
        first=0
        last=len(alist)-1
        mid = (first + last) //2
        if alist[mid] > item:
            return binarySearch2(alist[:mid],item)
        elif alist[mid] < item:
            return binarySearch2(alist[mid+1:],item)
        else:
            return True
testlist=[0,1,2,3,4,5,6,7,8]
print(binarySearch2(testlist,3))
print(binarySearch2(testlist,13))          
