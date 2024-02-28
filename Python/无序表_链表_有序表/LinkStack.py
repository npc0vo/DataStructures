class Node():
    def __init__(self,initdata):
        self.data=initdata
        self.next=None
    def getData(self):
        return self.data
    def getNext(self):
        return self.next
    def setNext(self,newnext):
        self.next=newnext
    def setData(self,newdata):
        self.data=newdata
class LinkStack():
    def __init__(self):
        self.head=None
        self.length=0
    def isEmpty(self):
        return self.head is None
    def size(self):
        return self.length
    def peek(self):
        return self.head.getData()
    def push(self,item):
        top=Node(item)
        top.setNext(self.head)
        self.head=top
        self.length+=1
    def pop(self):
        top_data=self.head.getData()
        temp=self.head.getNext()
        self.head=temp
        self.length-=1
        return top_data
