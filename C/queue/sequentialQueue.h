//
// Created by Npc on 2024/4/18.
//

#ifndef C_SEQUENTIALQUEUE_H
#define C_SEQUENTIALQUEUE_H
#include "stdio.h"
#include "stdlib.h"

/*队列是一个先进先出的数据结构*/
 /*队列的结点设计，我们可以设计出两个结构体，一个结构体Node表示结点，其中包含有一个data域和next指针*/
 typedef struct node{
     int data;
     node *next;
 }node;

//队列设计
typedef struct queue{
    node *front; //头指针
    node *rear; //尾指针
};

//初始化节点
node *initNode()
{
    node *n=(node *)malloc(sizeof (node));
    if(n==NULL)
    {
        exit(0);//如果节点开辟失败
    }
    return n;
}

//初始化队列
queue *initQueue()
{
    queue *q=(queue*) malloc(sizeof (queue));
    if(q==NULL)
    {
        exit(0);//如果队列开辟失败
    }
    //头尾指针均赋值NULL
    q->front=NULL;
    q->rear=NULL;
    return q;
}

//判断队列是否为空
int empty(queue *q)
{
    if(q->front==NULL)
    {
        return 1; //1-代表真，队列为空
    }
    else{
        return 0;
    }
    //或者直接使用return q->front==NULL
}

//入队操作
/* 1.首先需要特判一下队列是否为空
 * 2.如果队列为空，需要将头指针和尾指针同时指向第一个节点
 * 3.如果队列不为空，只需要将尾节点向后移动，通过不断移动next指针指向新的节点*/
void push(queue *q,int data)
{
    node *n=initNode();
    n->data=data;
    n->next=NULL;
    //采用尾差法
    if(empty(q))
    {
        q->front=n;
        q->rear=n;
    }
    else{
        q->rear->next=n;
        q->rear=n;
    }
}

//出队操作
/* 1.前提条件是队列不为空，因此要做一个判断
 * 2.如果队伍里只有一个元素,出队后需要将头尾指针置空，并free掉这个节点
 * 3.如果队伍里有两个以上的元素，将头指针指向头指针的下一个元素，并free掉当前元素*/
void pop(queue *q)
{
    node *n=q->front;
    if(empty(q))
    {
        printf("队列为空，无法出队");
        return;
    }
    //如果只有一个元素
    if(q->front==q->rear)
    {
        q->front=NULL;
        q->rear=NULL;
        free(n);
    }
    else//如果队里有两个以上的元素
    {
        q->front=q->front->next;
        free(n);
    }
}

//遍历队列-打印元素
void print_queue(queue *q)
{
    node *n=initNode();
    n=q->front;
    if(empty(q))
    {
        return;
    }
    while(n!=NULL)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
    printf("\n");
}
#endif //C_SEQUENTIALQUEUE_H
