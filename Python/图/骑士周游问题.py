'''
在8×8的国际象祺棋盘上，合格的“周游
数量有1.305×1035这么多，走棋过程中
失败的周游就更多了
?采用图搜索算法，是解决骑士周游问题最
容易理解和编程的方案之一
?解决方案还是分为两步：
首先将合法走棋次序表示为一个图
采用图搜索算法搜寻一个长度为（行×列-1）的
路径，路径上包含每个顶点恰一次
'''
from Graph import *
#bdSize代表棋盘大小
def genLegalMoves(x,y,bdSize):
    newMoves=[]
    moveOffsets=[(-1,-2),(-1,2),(-2,-1),(2,-1),
                 (-2,1),(1,2),(1,-2),(2,1)]
    for i in moveOffsets:
        newX=x+i[0]
        newY=y+i[1]
        if legalCoord(newX,bdSize) and legalCoord(newY,bdSize):
            newMoves.append((newX,newY))

    return newMoves



def legalCoord(x,bdSize):
    if x >=0 and x< bdSize:
        return True
    else:
        return False

def knightGraph(bdSize):
    ktGraph=Graph()
    for row in range(bdSize):
        for col in range(bdSize):
            nodeID=posToNodeId(row,col,bdSize)
            #单步合法走棋步骤
            newPositions=genLegalMoves(row,col,bdSize)
            for e in newPositions:
                #添加边和顶点
                nid=posToNodeId(e[0],e[1],bdSize)
                ktGraph.addEdge(nodeID,nid)
    return ktGraph


def posToNodeId(row,col,bdSize):
    return row*bdSize+col

