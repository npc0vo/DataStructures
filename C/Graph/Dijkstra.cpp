//
// Created by Npc on 2024/4/30.
//

#include "Dijkstra.h"
int main()
{
    int i,j;
    MGraph g;
    createDN(g);
    int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//最短路径数组p
    int D[MAX_VERTEX_NUM];//最短距离数组D
    ShortestPath_Dijkstra(g,0,p,D);

    cout<<"最短路径数组p[i][j]如下："<<endl;
    for(i=0;i<g.vexnum;i++)
    {
        for(j=0;j<g.vexnum;j++)
        {
            cout<<setw(3)<<p[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<g.vexs[0]<<"到各顶点的最短路径及长度为:"<<endl;
    for(i=0;i<g.vexnum;i++)
    {
        if(i!=0&&D[i]!=INFINITY)
        {
            cout<<g.vexs[0]<<"-"<<g.vexs[i]<<"的最短路径长度为："<<D[i];
            cout<<"  最短路径为 ：";
            for(j=0;j<g.vexnum;j++)
            {
                if(p[i][j]>-1)
                {
                    cout<<g.vexs[p[i][j]]<<" ";
                }
            }
            cout<<endl;
        }else if(D[i]==INFINITY)
        {
            cout<<g.vexs[0]<<"-"<<g.vexs[i]<<":"<<"不可达"<<endl;
        }
    }
    system("pause");
    return 0;
}
/*测试数据
 * 请输入顶点数和边数:5 7
请输入顶点：A B C D E
请输入边和权值A D 2
A B 4
B D 1
D C 1
B C 4
D E 7
C D 1
最短路径数组p[i][j]如下：
 -1  -1  -1  -1  -1
  0   1  -1  -1  -1
  0   3   2  -1  -1
  0   3  -1  -1  -1
  0   3   4  -1  -1
A到各顶点的最短路径及长度为:
A-B的最短路径长度为：4  最短路径为 ：A B
A-C的最短路径长度为：3  最短路径为 ：A D C
A-D的最短路径长度为：2  最短路径为 ：A D
A-E的最短路径长度为：9  最短路径为 ：A D E*/