//
// Created by Npc on 2024/4/30.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXNODES 100
typedef struct Node{
    char stationName[50];
    float dist;
    int indegree;
    struct Node*next;
}Node,Station;

typedef struct{
    char stationName[50];//每个邻接表的第一个站名
    Node *Head;
}StationList,Head;

StationList stations[100];
int stationCount=0;
/* int findStation(char *from)
{
    for(int i=0;i<MAXNODES;i++)
    {
        if(strcmp(stations[i].stationName,from)==0)
        {
            return i;
        }
    }
    return -1; //表示未找到
} */
/* void addEdge(char *from,char *to,float dist)
{
    Node*toStation=(Node*) malloc(sizeof (Node));
    toStation->next=NULL;
    toStation->indegree=0;
    strcpy(toStation->stationName,to);
    int idx= findStation(from);
    if(idx==-1)
    {
        Node*fromStation=(Node *) malloc(sizeof (Node));
        fromStation->indegree=0;
        fromStation->next=NULL;
        fromStation->dist=dist;
        strcpy(fromStation->stationName,from);
        stations[stationCount].Head=fromStation;
        stations[stationCount].Head->next=toStation;
        stationCount++;
    }
    else{
        Node*temp=stations[idx].Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=toStation;
        toStation->indegree++;
    }
} */
void printDegrees(int idx)
{
    //计算出度
    int outDegree=0;
    Node *temp=stations[idx].Head;
    while(temp!=NULL)
    {
        temp=temp->next;
        outDegree++;
    }
    int degree=outDegree+stations[idx].Head->indegree;
    printf("%s %d\n",stations[idx].Head->stationName,degree);
}
/* int main()
{
    char *from= (char*)malloc(sizeof(char)*50);
    char *to=(char *) malloc(sizeof (char )*50);
    float dist;
    //处理输入
    while(1)
    {
        scanf("%s",from);
        if(strcmp(from,"END!")==0)
        {
            break;
        }
        scanf("%s %f",to,&dist);

        //开始构建邻接表
        addEdge(from,to,dist);
    }
    //计算每个转接站的相邻站，入度加出度，出度好算，怎么算入度
    for(int i=0;i<stationCount;i++)
    {
        printDegrees(i);
    }
    system("pause");
} */
int findStation(char *from)
{
    for(int i=0;i<MAXNODES;i++)
    {
        if(strcmp(stations[i].stationName,from)==0)
        {
            return i;
        }
    }
    return -1;
}

void addStation(char *name)
{
    int index = findStation(name);
    if (index == -1) {
        strcpy(stations[stationCount].stationName, name);
        stations[stationCount].Head = NULL;
        stationCount++;
    }
}

void addEdge(char *from, char *to, float dist)
{
    int fromIndex = findStation(from);
    int toIndex = findStation(to);
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->stationName, to);
    newNode->dist = dist;
    newNode->next = stations[fromIndex].Head;
    stations[fromIndex].Head = newNode;
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->stationName, from);
    newNode->dist = dist;
    newNode->next = stations[toIndex].Head;
    stations[toIndex].Head = newNode;
}

int main()
{
    char from[50], to[50];
    float dist;
    while (scanf("%s", from) != EOF && strcmp(from, "END!") != 0) {
        scanf("%s %f", to, &dist);
        addStation(from);
        addStation(to);
        addEdge(from, to, dist);
    }
    for (int i = 0; i < stationCount; i++) {
        Node *node = stations[i].Head;
        int count = 0;
        while (node != NULL) {
            count++;
            node = node->next;
        }
        if (count > 2) {
            printf("%s %d\n", stations[i].stationName, count);
        }
    }
    system("pause");
    return 0;
}

