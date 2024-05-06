//
// Created by Npc on 2024/5/6.
//

#ifndef C_FLOYED_H
#define C_FLOYED_H
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "limits.h"
using namespace std;

class Graph_DG{
private:
    int vexnum;//图的顶点个数
    int edge;//图的边数
    int **arc;//邻接矩阵
    int **dis;//记录各个顶点最短路径的信息
    int **path;//记录各个最短路径的信息
public:
    //构造函数
    Graph_DG(int vexnum,int edge);
    //析构函数
    ~Graph_DG();
    //判断我们输入的边的信息是否合法
    //顶点从1开始编号
    bool check_edge_value(int start,int end,int weight);
    //创建图
    void createGraph(int);
    //打印邻接矩阵
    void printAdjMatrix();
    //求最短路径
    void Floyd();
    //打印最短路径
    void printPath();
};
Graph_DG::Graph_DG(int vexnum, int edge) {
    //初始化顶点数和边数
    this->vexnum=vexnum;
    this->edge=edge;
    //为邻接矩阵开辟空间和赋初值
    arc=new int*[this->vexnum];
    dis=new int*[this->vexnum];
    path=new int*[this->vexnum];
    for(int i=0;i<this->vexnum;i++)
    {
        arc[i]=new int[this->vexnum];
        dis[i]=new int[this->vexnum];
        path[i]=new int[this->vexnum];
        //初始化邻接矩阵
        for(int k=0;k<this->vexnum;k++)
        {
            //邻接矩阵初始化为无穷大
            arc[i][k]=INT_MAX;
        }
    }
}

//析构函数
Graph_DG::~Graph_DG() {
    //释放内存
    for(int i=0;i<this->vexnum;i++)
    {
        delete this->arc[i];
        delete this->dis[i];
        delete this->path[i];
    }
    delete dis;
    delete arc;
    delete path;
}

//判断我们每次的输入是否合法
//顶点从1开始编号
bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if(start<1||end<1||start>vexnum||end>vexnum||weight<0)
    {
        return false;
    }
    return true;
}


void Graph_DG::createGraph(int kind) {
    cout<<"请输入每条边的起点和终点（顶点编号从1开始)以及权重"<<endl;
    int start;
    int end;
    int weight;
    int count=0;
    while(count!=this->edge)
    {
        cin>>start>>end>>weight;
        //首先判断边的信息是否合法
        while(!this->check_edge_value(start,end,weight))
        {
            cout<<"输入的边的信息不合法，请重新输入"<<endl;
            cin>>start>>end>>weight;
        }
        //对邻接矩阵对应上的点赋值
        arc[start-1][end-1]=weight;
         //如果是无向图
         if(kind==2)
            arc[end-1][start-1]=weight;
         ++count;
    }
}

void Graph_DG::printAdjMatrix() {
    cout<<"图的邻接矩阵为:"<<endl;
    int count_row=0;//打印行的标签
    int count_col=0;//打印列的标签

    //开始打印
    while(count_row!=this->vexnum){
        count_col=0;
        while (count_col!= this->vexnum)
        {
            if(arc[count_row][count_col]==INT_MAX)
            {
                cout<<"∞"<<" ";
            }
            else{
                cout<<arc[count_row][count_col]<<" ";
            }
            ++count_col;
        }
        cout<<endl;
        ++count_row;
    }
}

//最短路径算法Floyd
void Graph_DG::Floyd() {
    int row=0;
    int col=0;

    //把矩阵dis初始化为邻接矩阵的值
    for(row=0;row<this->vexnum;row++)
    {
        for(col=0;col<this->vexnum;col++)
        {
            this->dis[row][col]=this->arc[row][col];
            //矩阵P的初值则为每个边的终点顶点的下标
            this->path[row][col]=col;
        }
    }

    //动态规划的思想，插入每个中间点求每个点对的最短路径
    int temp=0;
    int select=0;
    for(temp=0;temp<this->vexnum;temp++)
    {
        for(row=0;row<this->vexnum;row++)
        {
            for(col=0;col<this->vexnum;col++)
            {
                //为了防止溢出，引入一个select值
                select=(dis[row][temp]==INT_MAX||dis[temp][col]==INT_MAX)?INT_MAX:(dis[row][temp]+dis[temp][col]);
                if(this->dis[row][col]>select)
                {
                    //更新D矩阵
                    this->dis[row][col]=select;
                    //更新P矩阵
                    this->path[row][col]=this->path[row][temp];
                }

            }

        }
    }
}

void Graph_DG::printPath() {
    cout<<"各个顶点对的最短路径:"<<endl;
    int row=0;
    int col=0;
    int temp=0;
    for(row=0;row<this->vexnum;row++)
    {
        for(col=row+1;col<this->vexnum;col++)
        {
            cout<<"v"<<to_string(row+1)<<"---"<<"v"<<to_string(col+1)<<"weight:"<<
            this->dis[row][col]<<"path:"<<"v"<<to_string(row+1);
            //循环输出途径的每条路径
            temp=path[row][col];

            while(temp!=col)
            {
                cout<<"-->"<<"v"<<to_string(temp+1);
                temp=path[temp][col];
            }

            cout<<"-->"<<"v"<<to_string(col+1)<<endl;

        }
        cout<<endl;
    }
}
#endif //C_FLOYED_H
