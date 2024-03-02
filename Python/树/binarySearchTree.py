class BinarySearchTree:
    def __init__(self):
        self.root=None
        self.size=0
    def length(self):
        return self.size
    def __len__(self):
        return self.size
    def __iter__(self):
        return self.root.__iter__()
    def put(self,key,val):
        if self.root:
            self._put(key,val,self.root)
        else:
            self.root=TreeNode(key,val)
        self.size+=1
    def _put(self,key,val,currentNode):
        #递归左子树
        if key <currentNode.key:
            if currentNode.hasLeftChild():
                self._put(key,val,currentNode.leftChild)
            else:
                currentNode.leftChild=TreeNode(key,val,parent=currentNode)
        #递归右子树
        else:
            if currentNode.hasRightChild():
                self._put(key,val,currentNode.rightChild())
            else:
                currentNode.rightChild=TreeNode(key,val,parent=currentNode)
    def __setitem__(self,k,v):
        self.put(k,v)
    #从树中找到key所在的节点取到payload
    def get(self,key):
        if self.root:
            #这是一个递归函数
            res=self._get(key,self.root)
            if res:
                return res.payload
            else:
                return None
        else:
            return None
    
    def _get(self,key,currentNode):
        if not currentNode:
            return None
        elif currentNode.key==key:
            return currentNode
        elif key<currentNode.key:
            return self._get(key,currentNode.leftChild)
        else:
            return self._get(key,currentNode.rightChild)
    
    def __contains__(self,key):
        if self._get(key,self.root):
            return True
        else:
            return False

    #用_get找到要删除的节点，然后调用remove来删除，找不到则提示错误
    def delete(self,key):
        if self.size>1:
            nodeToRemove=self._get(key,self.root)
            if nodeToRemove:
                self.remove(nodeToRemove)
                self.size-=1
            else:
                raise KeyError('error,kry not in tree')
        elif self.size==1 and self.root.key==key:
            self.root=None
        else:
            raise KeyError('error,key not in tree')
    
    #__delitem__特殊方法 实现del myZipTree['PKU']
        def __delitem__(self,key):
            self.delete(key)
        
    #remove方法
'''
    def remove(currentNode):
        if currentNode.isLeaf():
            #M没有子节点直接删除
            if currentNode == currentNode.parent.leftChild:
                currentNode.parent.leftChild=None
            else:
                currentNode.parent.rightChild=None
        else: #有一个子节点
            if currentNode.hasLeftChild():
                if currentNode.isLeftChild():
                    #左子节点删除
                    currentNode.leftChild.parent=currentNode.parent
                    currentNode.parent.leftChild=currentNode.leftChild
                    #右子节点删除
                    currentNode.rightChild.parent=currentNode.parent
                    currentNode.parent.rightChild=currentNode.rightChild
                    #根节点删除
                else:
                    currentNode.

'''




    


class TreeNode:
    def __init__(self,key,val,left=None,\
                 right=None,parent=None):
        self.key=key
        self.payload=val
        self.leftChild=left
        self.rightChild=right
        self.parent=parent
    def hasLeftChild(self):
        return self.leftChild
    def hasRightChild(self):
        return self.rightChild
    def isLeftChild(self):
        return self.parent and \
        self.parent.leftChild==self
    def isRightChild(self):
        return self.parent and \
        self.parent.rightChild==self
    def isRoot(self):
        return not self.parent
    def isLeaf(self):
        return not (self.rightChild or self.leftChild)
    def hasAnyChild(self):
        return self.rightChild or self.leftChild
    def hasBothChild(self):
        return self.rightChild and self.leftChild
    def replaceNodeData(self,key,value,lc,rc):
        self.key=key
        self.payload=value
        self.leftChild=lc
        self.rightChild=rc
        if self.hasLeftChild():
            self.leftChild.parent=self
        if self.hasRightChild():
            self.rightChild.parent=self
    def __iter__(self):
        if self:
            if self.hasLeftChild():
                for elem in self.leftChild:
                    yield elem
            yield self.key
            if self.hasRightChild():
                for elem in self.rightChild:
                    yield elem

                
    
