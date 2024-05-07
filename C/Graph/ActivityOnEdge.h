//
// Created by Npc on 2024/5/7.
//

#ifndef C_ACTIVITYONEDGE_H
#define C_ACTIVITYONEDGE_H


//AOE图的前提是该图为有向无环图
/*AOE图求关键路径，我们可以把他比作一个工程，
 * 后续的工程需要前面的工程做铺垫，
 * 等到前面的所有工作都结束之后才可以开展后续的工作，
 * 有向赋权图就可以完成这样的表示。从起点到终点的路径不只有一条，
 * 但是需要路径上全部的活动都完成后，
 * 整个工程才算结束。
 * 因此，完成整个工程所需的最短时间取决于从起点到终点的最长路径长度，
 * 即这条路径上所有活动持续时间之和。
/*各种概念
 关键路径：在AOE网中，从始点到终点具有最大路径长度
 （该路径上的各个活动所持续的时间之和）的路径称为关键路径。
 关键活动：关键路径上的活动称为关键活动。*/
/*关键路径的最早发生事件与最晚发生事件是一样的
 * 事件发生最早时间ve[k]，事实上可以表示为从起点到k顶点的最长路径,因为根据问题的定义，必须要等所有路径上所有事件都做完，才能干k
 * 事件发生最晚时间vl[k],通过终点发生的最早事件，我们可以得到整个工程的用时，也是v[l],最迟时间是工程用时-k节点到终点的最长路径*/


#include "iostream"
#include "queue"
using namespace std;
const int MaxSize=20;
const int INF=INT_MAX;
int ve[MaxSize];
int vl[MaxSize];
int e[MaxSize];
int l[MaxSize];

typedef struct Edge
{
    int from;
    int to;
    int e;
    int l;
} Edge;

class Graph{
    int arcNum;//边的数量
    int vertexNum;//节点数量
    int arc[MaxSize][MaxSize];//定义一个邻接矩阵
    Edge edge[MaxSize]; //边集

public:
    //构造函数,初始化邻接矩阵,
    Graph(int n,int e)//n是点的数量，e的边的数量
    {
        arcNum=e;
        vertexNum=n;
        for(int i=1;i<=vertexNum;++i)
        {
            for(int j=1;j<=vertexNum;++j)
            {
                if(i==j)
                {
                    arc[i][j]=0;
                }else{
                    arc[i][j]=INF;
                }
            }
        }
        //输入数据构造邻接矩阵
        cout<<"请输入 起点 重点 权重"<< endl;
        for(int i=1;i<=arcNum;++i)
        {
            int from,to,weight;
            cin>>from>>to>>weight;
            arc[from][to]=weight;
            edge[i].from=from;
            edge[i].to=to;
        }
    }

    //求最早时间
    void setve()
    {
        int visited[MaxSize];
        queue<int>q;
        q.push(1);
        //初始化
        for(int i=1;i<=vertexNum;++i)
        {
            ve[i]=0;
            visited[i]=0;
        }

        visited[1]=1;
        while (!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=1;i<=vertexNum;++i)
            {
                if(arc[k][i]!=INF&&ve[k]+arc[k][i]>ve[i])
                {
                    ve[i]=ve[k]+arc[k][i];
                    if(visited[i]==0)
                    {
                        q.push(i);
                    }
                    visited[i]=1;
                }
            }
        }
    }


    void setvl()
    {
        queue<int>q;
        int visited[MaxSize];
        q.push(vertexNum);
        for(int i=1;i<=vertexNum;++i)
        {
            vl[i]=ve[vertexNum];
            visited[i]=0;
        }

        while (!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=0;i<vertexNum;i++)
            {
                if(arc[i][k]!=INF&&vl[k]-arc[i][k]<vl[i])
                {
                    vl[i]=vl[k]-arc[i][k];
                    if(!visited[i])
                    {
                        q.push(i);
                    }
                    visited[i]=1;
                }
            }
        }
    }

    void sete()
    {
        for(int i=1;i<=arcNum;i++)
        {
            edge[i].e=ve[edge[i].from];
        }
    }

    void setl()
    {
        for(int i=1;i<=arcNum;i++)
        {
            edge[i].l=vl[edge[i].to]-arc[edge[i].from][edge[i].to];
        }
    }

    void getPoint()
    {
        int count=0;
        for(int i=1;i<=arcNum;++i)
        {
            if(edge[i].e==edge[i].l)
            {
                cout<<"v"<<edge[i].from<<" ";
                count=i;
            }
        }
        cout<<"v"<<edge[count].to;
    }
};
#endif //C_ACTIVITYONEDGE_H
