class Vertex: #这是一个顶点类，包含顶点信息以及顶点连接边信息
    def __init__(self,key):
        self.id=key
        self.connectedTo={}
    def addNeighbor(self,nbr,weight=0):
        self.connectedTo[nbr]=weight
        #nbr是顶点对象的key
    def __str__(self):
        return str(self.id)+"connectedTo:"\
        +str([x.id for x in self.connectedTo])
    def getConnections(self):
        return self.connectedTo.keys
    def getId(self):
        return self.id
    def getWeight(self,nbr):
        return self.connectedTo[nbr]


class Graph: #保存了包含所有顶点的主表
    def __init__(self):
        self.vertList={}
        self.numVertices=0
    
    def addVertex(self,key):
        self.numVertices=self.numVertices+1
        newVertex=Vertex(key)
        self.vertList[key]=newVertex
        return newVertex
    def getVertex(self,n):
        if n in self.vertList:
            #通过key找顶点
            return self.vertList[n]

        else:
            return None
    def __contains__(self,n):
        return n in self.vertList
    
    #添加一条边
    def addEdge(self,f,t,cost=0):
        #如何出现不存在的顶点就需要先进行添加
        if f not in self.vertList:
            nv=self.addVertex(f)
        if t not in self.vertList:
            nv=self.addVertex(t)
        self.vertList[f].addNeighbor(self.vertList[t],cost)

    def getVertices(self):
        return self.vertList.keys()
    
    def __iter__(self):
        return iter(self.vertList.values())
    
class Queue:
    def __init__(self):
        self.items=[]
    def isEmpty(self):
        return self.items ==[]
    def enqueue(self,item):
        self.items.insert(0,item)
    def dequeue(self):
        return self.items.pop()
    def size(self):
        return len(self.items)


def bfs(g,start):
    start.setDistance(0)
    start.setPred(None)
    vertQueue=Queue()
    vertQueue.enqueue(start)
    while(vertQueue.size>0):
        currentVert=vertQueue.dequeue()
        for nbr in currentVert.getConnections():
            if (nbr.getcolor()=='white'):
                nbr.setColor('gray')
                nbr.setDistance(currentVert.getDistance()+1)
                nbr.setPred(currentVert)
                vertQueue.enqueue(nbr)
        currentVert.setColor('black')

            