#ADT完全二叉树的实现
#以1开始
#左子节点下标2p 右子节点2p+1
#
class BinHeap:
    def __init__(self):
        self.heapList=[0]
        self.currentSize=0
    def percUp(self,i):
        while i//2 >0:
            if self.heapList[i] < self.heapList[i//2]
                tmp=self.heapList[i//2]
                self.heapList[i//2]=self.heapList[i]
                self.heapList[i]=tmp
            i=i//2
    def insert(self,k):
        self.heapList.append(k)
        self.currentSize=self.currentSize+1
        self.percUp(self.currentSize)
    #移走整个堆中最小的key:根节点heapList[i]
    def delMin(self):
        retval=self.heapList[1]
        self.currentSize-=1
        self.heapList.pop()
        self.percDown(1)
        return retval
    def minChild(self,i):
        if i*2+1>self.currentSize:
            return i*2
        else:
            if self.heapList[i*2]<self.heapList[i*2+1]:
                return i*2
            else:
                return i*2+1

