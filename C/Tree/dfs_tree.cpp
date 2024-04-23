//
// Created by Npc on 2024/4/22.
//
/*深度优先搜索算法（英语：Depth-First-Search，简称DFS）是一种用于遍历或搜索树或图的算法。
 * 沿着树的深度遍历树的节点，尽可能深的搜索树的分支。
 * 当节点v的所在边都己被探寻过或者在搜寻时结点不满足条件，
 * 搜索将回溯到发现节点v的那条边的起始节点。
 * 整个进程反复进行直到所有节点都被访问为止。属于盲目搜索,
 * 最糟糕的情况算法时间复杂度为O(!n)，DFS搜索的过程访问可以称之为DFS序。*/


/* 而即时对于一颗深度为n的二树，在没有任何优化的情况下适用DFS去搜索访问数据，其算法的时间复杂度也高达O（2^n），
 * 在数据较大的情况下DFS是无法满足程序的时间要求，
 * 这就会涉及到一个思路——剪枝，
 * 即通过现有的数据判断接下来的数据无法再满足解，
 * 直接将当前结点以后的所有数据舍弃，
 * 遍历不再访问，通过精心设计的剪纸可以使得DFS搜索的效果得到很大提升。*/



/*对于一个标准的DFS模板而言，其包括了以下的内容：

bool check(参数)
{
    if(满足条件)
        return true ;
    return false;
}

void dfs(int step)
{
        判断边界
        {
            相应操作
        }
        尝试每一种可能
        {
               满足check条件
               标记
               继续下一步dfs(step+1)
               恢复初始状态（回溯的时候要用到）
        }
}*/

/*dfs其实就是用递归模拟树*/
/*例题1:从n个不同元素中任取m（m≤n）个元素，
 * 按照一定的顺序排列起来，叫做从n个不同元素中取出m个元素的一个排列。
 * 当m=n时所有的排列情况叫全排列。*/
#include "iostream"
#include "cmath"
#include "stdio.h"
#include "stdlib.h"
using namespace std;
int p[10]={0};
bool vis[10]={0};

int n;
void dfs1(int x){
    if(x==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)//i其实相当于模拟树的深度
    {
        if(!vis[i])
        {
            p[x]=i;
            vis[i]= true;//标记
            dfs1(x+1);
            vis[i]= false;// 回溯
        }
    }
}

/*程序员是善于思考的，有一天他在爬楼梯的时候想出一个问题。
  楼梯有 n 级。每次你只能爬 1 级或者 3 级，那么你有多少种方法爬到楼梯的顶部？
  开始的时候在0级楼梯，顶级在第n级。*/
typedef long long ll;
ll ans,m;
void dfs2(ll k)
{
    if(k==m)
    {
        ans+=1;
        return;
    }
    else if(k>n)
    {
        return;
    }
    dfs2(k+1);
    dfs2(k+3);
}
int main()
{
    cout<<"请输入n:";
    cin>>n;
    cout<<"全排列组合有:"<<endl;
    dfs1(1);
    cout<<"以下是例题2的解答:"<<endl;
    cout<<"你想知道到达第几级的方法数:";
    cin>>m;
    ans=0;
    dfs2(0);
    printf("\n");
    cout<<ans<<endl;
    system("pause");
    return 0;
}