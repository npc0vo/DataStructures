//
// Created by Npc on 2024/4/23.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
#define MAX_NODES 200


typedef struct arc
{
    char name[20];
    float dist;
    struct arc* next;
} arc;

typedef struct Head
{
    char name[20];
    arc* add;
} Head;

void dijkstra(int n, float w[][MAX_NODES], int startnode, int endnode,Head G[]);

int main()
{
    int i, j, k, start_index, end_index;
    int count;
    char start[20];
    char end[20];
    float dist;
    Head G[MAX_NODES];
    int n = 0;

    for(i = 0; i < MAX_NODES; i++)
    {
        strcpy(G[i].name, "");
        G[i].add = NULL;
    }

    // 输入站点信息
    while(1)
    {
        scanf("%s", start);
        if(strcmp(start, "END!") == 0)
        {
            break;
        }
        scanf("%s %f", end, &dist);

        //查找起点是否存在
        for(i = 0; i < MAX_NODES; i++)
        {
            if(strcmp(G[i].name, start) == 0)
            {
                break;
            }
        }
        if(i == MAX_NODES)
        {
            for(i = 0; i < MAX_NODES; i++)
            {
                if(strcmp(G[i].name, "") == 0)
                {
                    strcpy(G[i].name, start);
                    count++;
                    G[i].add = NULL;

                    break;
                }
            }
        }

        arc* arcnode = (arc*)malloc(sizeof(arc));
        strcpy(arcnode->name, end);
        arcnode->dist = dist;
        arcnode->next = NULL;

        if(G[i].add == NULL)
        {
            G[i].add = arcnode;
        }
        else
        {
            arc* temp = G[i].add;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = arcnode;

        }

        //查找终点是否存在
        for(j = 0; j < MAX_NODES; j++)
        {
            if(strcmp(G[j].name, end) == 0)
            {
                break;
            }
        }

        if(j == MAX_NODES)
        {
            for(j = 0; j < MAX_NODES; j++)
            {
                if(strcmp(G[j].name, "") == 0)
                {
                    strcpy(G[j].name, end);
                    G[j].add = NULL;
                  	count++;//正确
                    break;
                }
            }
        }


    }
    n = count; //总站点数
	int num[n];
	int c1[n],c2[n];
    for(i=0;i<n;i++)
    num[i]=0,c1[i]=0,c2[i]=0;


    // 构建邻接矩阵
    float w[MAX_NODES][MAX_NODES];
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            w[i][j] = 0;
        }
    }

    for(i = 0; i <n; i++)
    {
        arc* temp = G[i].add;
        while(temp != NULL)
{
for(j = 0; j < n; j++)
{
if(strcmp(G[j].name, temp->name) == 0)
{
break;
}
}
w[i][j] = temp->dist;
temp = temp->next;
}
}

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(w[i][j]>0)
		{
		num[j]++;
		num[i]++;
		c2[j]++;
		c1[i]++;
		}
	}
}
for(i=0;i<n;i++)
{
	if(num[i]>1&&(c1[i]>=2||c2[i]>=2))
	printf("%s %d\n",G[i].name,num[i]);
}
return 0;
}
