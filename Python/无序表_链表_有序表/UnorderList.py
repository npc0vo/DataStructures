class Node:
    def __init__(self,initdata):
        self.data=initdata
        self.next=None
    def getData(self):
        return self.data
    def getNext(self):
        return self.next
    def setData(self,newdata):
        self.data=newdata
    def setNext(self,newnext):
        self.next=newnext
class UnorderedList:
    def __init__(self):
        self.head=None
    def isEmpty(self):
        return self.head==None  
    def add(self,item):
        temp=Node(item)
        temp.setNext(self.head)
        self.head=temp
    def size(self):
        current=self.head
        count=0
        while current!=None:
            count+=1
            current=current.getNext()
    def search(self,item):
        current=self.head
        found=False
        while current!=None and not found:
            if current.getData()==item:
                found=True
            else:
                current=current.getNext()
        return found
    def remove(self,item):
        prev=None
        current=self.head
        found=False
        while not found:
            if current.getData()==item:
                found=True
            else:
                prev=current
                current=current.getNext()
        #如果是删除第一个节点不要忘了否则bug
        if prev == None:
            self.head=current.getNext
        else:
            prev.setNext(current.getNext())
