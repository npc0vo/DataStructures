//
// Created by Npc on 2024/5/7.
//

#include "ActivityOnEdge.h"
int main()
{
    int n,e;
    cout<<"请输入图的点数和边数"<<endl;
    cin>>n>>e;
    Graph G(n,e);
    G.setve();
    G.setvl();
    G.sete();
    G.setl();
    G.getPoint();
    system("pause");
    return 0;
}

/*请输入图的点数和边数
9
11
请输入 起点 重点 权重
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
v1 v2 v5 v5 v7 v8 v9  //两条关键路径
 请按任意键继续. . .*/