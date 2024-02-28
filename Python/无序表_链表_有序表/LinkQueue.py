class Node():
    def __init__(self,initdata):
        self.data=initdata
        self.next=None
    def setData(self,newdata):
        self.data=newdata
    def setNext(self,newnext):
        self.next=newnext
    def getData(self):
        return self.data
    def getNext(self):
        return self.next
class LinkQueue():
    def __init__(self):
        self.head=None
        self.tail=None
        self.length=0
    def isEmpty(self):
        return self.head is None
    def size(self):
        return self.length
    def enqueue(self,item):
        tail=Node(item)
        if self.head is None:
            self.head.setNext(tail)
        else:
            self.tail.setNext(tail)
            self.tail=tail
        self.length+=1
    def dequeue(self):
        top_item=self.head.getData()
        if self.head==self.tail:
            self.head=self.tail=None
        else:
            self.head=self.head.getNext()
        self.length-=1
        return top_item
    

