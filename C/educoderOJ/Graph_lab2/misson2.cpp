//
// Created by Npc on 2024/4/30.
//
//
// Created by Npc on 2024/4/30.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXNODES 100
#define INFINITY 65535
float dist[MAXNODES];
int prev[MAXNODES];
int visited[MAXNODES];
char source[50], destination[50];

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
void dijkstra(char *source)
{
    for (int i = 0; i < stationCount; i++) {
        dist[i] = INFINITY;
        prev[i] = -1;
        visited[i] = 0;
    }
    int sourceIndex = findStation(source);
    dist[sourceIndex] = 0;
    for (int i = 0; i < stationCount; i++) {
        int u = -1;
        for (int j = 0; j < stationCount; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = 1;
        Node *node = stations[u].Head;
        while (node != NULL) {
            int v = findStation(node->stationName);
            float alt = dist[u] + node->dist;
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
            }
            node = node->next;
        }
    }
}

/* void printPath(char *destination)
{
    int u = findStation(destination);
    if (prev[u] != -1 || u == findStation(source)) {
        printPath(stations[prev[u]].stationName);
    }
    printf("%s ", destination);
} */
void printPath(char *destination)
{
    int u = findStation(destination);
    if (strcmp(destination, source) != 0) {
        printPath(stations[prev[u]].stationName);
    }
    printf("%s ", destination);
}
int main()
{
    char from[50], to[50];
    float distance;
    while (scanf("%s", from) != EOF && strcmp(from, "END!") != 0) {
        scanf("%s %f", to, &distance);
        addStation(from);
        addStation(to);
        addEdge(from, to, distance);
    }
/*    for (int i = 0; i < stationCount; i++) {
        Node *node = stations[i].Head;
        int count = 0;
        while (node != NULL) {
            count++;
            node = node->next;
        }
        if (count > 2) {
            printf("%s %d\n", stations[i].stationName, count);
        }
    }*/

    scanf("%s %s", source, destination);
    dijkstra(source);
    printPath(destination);
    printf("%.2f\n", dist[findStation(destination)]);
    system("pause");
    return 0;
}

