class Node():
    def __init__(self,initdata):
        self.data=initdata
        self.next=None
        self.prev=None
    def setData(self,newdata):
        self.data=newdata
    def setNext(self,newnext):
        self.next=newnext
    def setPrev(self,newprev):
        self.prev=newprev
    def getData(self):
        return self.data
    def getNext(self):
        return self.next
    def getPrev(self):
        return self.prev

class DoublyLinkedList():
    def __init__(self,it=None):
        self.head=None
        self.tail=None
        self.length=0
        if it is not None:
            for d in it:
                self.append(d)
    def isEmpty(self):
        return self.head is None
    def size(self):
        return self.length
    __len__=size
    def getTail(self):
        return self.tail
    def append(self,item): #加到最后一个
        temp=Node(item)
        if self.head is None: #如果是第一个加入则
            self.head=temp
            self.tail=temp
        else:
            self.tail.setNext(temp)
            temp.setPrev(self.tail)
            self.tail=temp
        self.length+=1
    def add(self,item): #加到第一个
        temp=Node(item)
        if self.head is None: #如果是第一个加入元素
            self.head=self.tail=temp
        else:
            self.head.setPrev(temp)
            temp.setNext(self.head)
            self.head=temp
        self.length+=1
    #在中间的任何位置插入
    def insert(self,idx,item): #插入为地idx个
        current,n=self.head,0
        while n<idx:
            current=current.getNext()
            n+=1
        if current is None:
            if self.head is None:
                self.add(item)
            else:
                self.append(item)
        else:
            #插入在中间位置
            idx=Node(item)
            current.getPrev().setNext(idx)
            idx.setPrev(current.getPrev())
            idx.setNext(current)
            current.setPrev(idx)
            self.length+=1
    def index(self,item):
        current,n=self.head,0
        while current is not None:
            current=current.getNext()
            if current.getData()==item:
                break
            n+=1
        else:
            return None
        return n
    def search(self,item):
        return self.index(item) is not None
    def delete(self,current): #删除current所引用的节点
        if self.head == current:
            #删除第一个节点
            self.head=current.getNext()
        if self.tail == current:
            self.tail=current.getPrev()
        if current.getPrev() is not None:
            current.getPrev().setNext(current.getNext())
        if current.getNext() is not None:
            current.getNext().setPrev(current.getPrev())
        self.length-=1
    def remove(self,item):  #删除内容为item的节点
        current=self.head
        while current is not None:
            if current.getData()==item:
                self.delete(current)
                break
            current=current.getNext()
    def pop(self,n=None):
        if n is None:
            n=self.length-1
        current,i=self.head,0
        while i<n:
            current=current.getNext()
            i+=1
        dat=current.getData()
        self.delete(current)
        return dat
    def __str__(self):
        tlist=[]
        current=self.head
        while current is not None:
            tlist.append(current.getData())
            current=current.getNext()
        return str(tlist)
    __repr__=__str__
    #遍历功能
    def __getitem__(self,key):
        if isinstance(key,int):  #检查key是否为int类型
            current,i=self.head,0
            while i < key:
                current = current.getNext()
                i+=1
            if current is not None:
                return current.getData()
            else:
                raise StopIteration
        elif isinstance(key,slice):  #实现切片功能
            start=0 if key.start is None else key.start
            stop=self.length if key.stop is None else key.stop
            step=1 if key.step is None else key.step
            current,i=self.head,0
            #定位到start
            while i < start:
                current=current.getNext()
                i+=1
            #开始拷贝
            dcopy=DoublyLinkedList()
            while i<stop:
                dcopy.append(current.getData())
                s=step
                while current is not None and s>0:
                    current=current.getNext()
                    s-=1
                i+=step
            return dcopy
    #判断相等功能
    def __eq__(self,other):
        if other is None or not isinstance(other,DoublyLinkedList):
            return False
        if len(self) != len(other):
            return False
        for s,o in zip(self,other):
            if s!=o:
                return False
        else:
            return True




        