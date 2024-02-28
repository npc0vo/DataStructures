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
class OrderedList:
    def __init__(self):
        self.head=None
    def isEmpty(self):
        return self.head==None  
    #比较重要
    def add(self,item):  
        prev=None
        current=self.head
        stop=False
        while current !=None and not stop:
            if current.getData()>item:
                stop=True
            else:
                prev=current
                current=current.getNext()
        #如果插入在表头
        temp=Node(item)
        if prev==None:
            self.head=temp
        else:
            prev.setNext(temp)
            temp.setNext(current)
    def size(self):
        current=self.head
        count=0
        while current!=None:
            count+=1
            current=current.getNext()
    #比较重要
    def search(self,item):
        current=self.head
        found=False
        stop=False
        while current!=None and not found and not stop:
            if current.getData()==item:
                found=True
            else:
                if current.getData()>item:
                    stop=True
                else:
                    current=current.getNext()
        return found
    #比较重要
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
   