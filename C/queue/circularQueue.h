//
// Created by Npc on 2024/4/18.
//

#ifndef C_CIRCULARQUEUE_H
#define C_CIRCULARQUEUE_H
#include "stdio.h"
#include "stdlib.h"
/*因为我们的入队和出队操作均是直接在其后面进行结点的链接和删除，
 * 这就造成其使用空间不断向出队的那一边偏移，产生假溢出
 * 通过使用循环队列就可以避免出现这种情况*/
#define maxsize 10
typedef struct cir_queue{
    int data[maxsize];
    int rear;
    int front;
}cir_queue;

//初始化
cir_queue *init()
{
    cir_queue *q=(cir_queue*) malloc(sizeof (cir_queue));
    if(q==NULL)
    {
        exit(0);
    }
    q->front=0;
    q->rear=0;
    return q;
}

//循环队列入队操作
/*接将rear向后移动即可，但是要注意判断，
 * 如果rear达到了队列的空间上线，
 * 将要从头继续开始移动，
 * 这里推荐使用余数法*/
void push(cir_queue *q,int data)
{
    if((q->rear+1)%maxsize==q->front)
    {
        printf("溢出，无法入队\n");
        return;
    }else{
        q->rear=(q->rear+1)%maxsize;
        q->data[q->rear]=data;
    }
}

void pop(cir_queue *q)
{
    //判断栈空
    if(q->rear==q->front)
    {
        printf("队列已空，无法出队\n");
        return;
    }else{
        q->data[q->front]=0;
        q->front=(q->front+1)%maxsize;
    }
}

//循环队列遍历操作
void printCirQueue(cir_queue *q)
{
    int i=q->front;
    while(i!=q->rear)
    {
        i=(i+1)%maxsize;
        printf("%d\t",q->data[i]);
    }
    printf("\n");
}
#endif //C_CIRCULARQUEUE_H
