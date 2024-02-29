'''
将海龟从原位置向北移动一步，以新位置递归调
用探索迷宫寻找出口；
如果上面的步骤找不到出口，那么将海龟从原位
置向南移动一步，以新位置递归调用探索迷宫；
如果向南还找不到出口，那么将海龟从原位置向
西移动一步，以新位置递归调用探索迷宫；
如果向西还找不到出口，那么将海龟从原位置向
东移动一步，以新位置递归调用探索迷宫；
如果上面四个方向都找不到出口，那么这个迷宫
没有出口！
需要有个机制记录海龟所走过的路径
沿途洒“面包屑”，一旦前进方向发现“面包屑
”，就不能再踩上去，而必须换下一个方向尝试
对于递归调用来说，就是某方向的方格上发现
面包屑”，就立即从递归调用返回上一级。
递归调用的“基本结束条件”↓
归纳如下：
海龟碰到“墙壁”方格，递归调用结束，返回失
败；
海龟碰到“面包屑”方格，表示此方格已访问过
递归调用结束，返回失败；
海龟碰到“出口”方格，即“位于边缘的通道”
方格，递归调用结束，返回成功！
海龟在四个方向上探索都失败，递归调用结束，
返回失败
'''
class Maze:
    def __init__(self,mazeFileName):
        rowsInMaze=0
        columnsInMaze=0
        self.mazelist=[]
        mazeFile=open(mazeFileName,'r')
        for line in mazeFile:
            rowList=[]
            col=0
            for ch in line[:-1]:
                rowList.append(ch)
                if ch== 'S':
                    self.startRow=rowsInMaze
                    self.startcol=col
                col+=1
            rowsInMaze+=1
            self.mazelist.append(rowList) #保存矩阵
            columnsInMaze=len(rowList)
    def searchFrom(maze,startRow,StartColumn):
        #1.碰到墙壁返回失败
        maze.updatePosition(startRow,StartColumn)
        if maze[startRow][StartColumn]== OBSTACLE:
            return False
        #2.碰到面包学或者死胡同，返回失败
        if maze[startRow][StartColumn]==TRIED or \
            maze[startRow][StartColumn]==DEAD_END:
            return False
        #3.碰到出口返回成功
        if maze.isExit(startRow,StartColumn):
            maze.updatePosition(startRow,StartColumn,PART_OF_PATH)
            return True
        #4.标记面包
        maze.updatePosition(startRow,StartColumn,TRIED)
        found=searchFrom(maze,startRow-1,StartColumn) or \
            searchFrom(maze,startRow+1,StartColumn) or \
                searchFrom(maze,startRow,StartColumn+1) or \
                searchFrom(maze,startRow,StartColumn-1)

        if found:
            maze.updatePosition(startRow,StartColumn,PART_OF_PATH)
        else:
            maze.updatePostion(startRow,StartColumn,DEAD_END)
        return found
        
