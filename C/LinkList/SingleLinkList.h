//
// Created by Npc on 2024/4/17.
//

#ifndef C_SINGLELINKLIST_H
#define C_SINGLELINKLIST_H
#include "stdlib.h"
#include "stdio.h"
//定义结点ADT
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkedList;  //Node表示结点，LinkedList表示指向Node结点类型的指针类型
// Function prototypes


//单链表的初始化
LinkedList listinit()
{
    Node *L;
    L=(Node*) malloc(sizeof(Node));
    if(L==NULL){
        printf("申请内存空间失败");
        exit(0);
    }
    L->next=NULL;
    return L;
}
//单链表的建立1:头插法建立单链表
LinkedList LinkedListCreatH(){
    Node *L;
    L=(Node *)malloc(sizeof(Node)); //申请头结点
    L->next=NULL;  //初始化一个空链表
    //即listinit()
    int x;
    while(scanf("%d",&x)!=EOF){
        Node *p;
        p=(Node *)malloc(sizeof(Node));
        p->data=x;
        p->next=L->next;
        L->next=p;
    }
    return L;
}
//单链表的建立2:尾插法建立单链表
LinkedList LinkedListCreatT(){
    Node *L;
    L=(Node*) malloc(sizeof(Node));
    L->next=NULL;
    Node *R;
    R=L;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        Node *p;
        p=(Node*) malloc(sizeof(Node));
        p->data=x;
        R->next=p;
        R=p;
    }
    R->next=NULL;
    return L;
}

//遍历单链表 ---打印，修改
void printList(LinkedList L)
{
    Node *p=L->next;
    int i=0;
    while(p)
    {
        printf("第%d个元素的值为:%d\n",++i,p->data);
        p=p->next;
    }
}
//修改单链表即遍历单链表，把值为x的元素修改为k
LinkedList LinkedListReplace(LinkedList L,int x,int k)
{
    Node *p=L->next;
    int i=0;
    while(p)
    {
        if(p->data==x)
        {
            p->data=k;
        }
        p=p->next;
    }
    return p;
}

//链表插入操作
/*
 * 1.查找到第i个位置
 * 2.将该位置的next指针修改为指向我们新插入的节点
 * 3.将新插入的节点next指针指向第i+1个位置*/
LinkedList LinkedListInsert(LinkedList L,int i,int x)
{
    Node *pre; //pre是前驱节点
    pre=L;
    int tempi=0;  //结点的下标
    for(tempi=1;tempi<i;tempi++)
    {
        pre=pre->next;
    }
    Node *p; //p是要插入的节点
    p=(Node *) malloc(sizeof (Node));
    p->data=x;
    p->next=pre->next;
    pre->next=p;

    return L;
}
//链表删除操作---删除L链表中值为x的结点
/*1.设置一个前驱结点指针pre，指向要删去的节点的前一个节点
 *2.pre的next指针指向删去节点的后一个节点
 *3.free掉原有的节点*/
LinkedList LinkedListDelete(LinkedList L,int x)
{
    Node *pre=L;
    Node *p=L->next; //指向要删除的节点
    while (p != NULL && p->data != x) {
        pre = p;
        p = p->next;
    }

    pre->next=p->next;
    free(p);
    return L;
}
#endif //C_SINGLELINKLIST_H
