//
// Created by Npc on 2024/4/17.
//

#ifndef C_DOUBLELINKEDLIST_H
#define C_DOUBLELINKEDLIST_H
#include "stdio.h"
#include "stdlib.h"
typedef struct line{
    int data;
    struct line *pre;
    struct line *next;
}line;


//双链表的创建
/*操作要点
 * 1.创建头结点
 * 2.创建一个新的结点
 * 3.将头结点和新结点相互链接
 * 4.再度创建新结点
 * */
line* initLine(line *head){
    int number,pos=1,input_data;//分别代表结点数量，当前位置，输入数据
    printf("请输入创建节点的大小\n");
    scanf("%d",&number);
    if(number<1)
    {
        return NULL;  //处理特殊情况
    }
    //创建头结点
    head=(line *)malloc(sizeof(line));
    head->pre=NULL;
    head->next=NULL;
    printf("输入第%d个数据\n",pos++);
    scanf("%d",&input_data);
    head->data=input_data;

    //建立双向链表
    line *list=head; //建立一个尾指针
    while(pos<=number)
    {
        line *body=(line *) malloc(sizeof(line));
        body->pre=NULL;
        body->next=NULL;
        printf("输入第%d个数据\n",pos++);
        scanf("%d",&input_data);
        body->data=input_data;

        list->next=body;
        body->pre=list;
        list=list->next;
    }

    return head;
}


//插入双链表
/* 1.首先创建一个节点
 * 2.选中这个新节点
 * 3.将其pre指针指向所需插入位置的前一个节点
 * 4.将其next指针指向所需插入位置的后一个节点
 * 5.将前一个节点的next指向该节点
 * 6.将后一个节点的pre指向该节点*/
line *insertLine(line *head,int pos,int data)//参数声明:pos:要插入的位置，插入是pos的前一个节点 data：要插入的值
{
    line *temp=(line*) malloc(sizeof(line));
    temp->data=data;
    temp->pre=NULL;
    temp->next=NULL;

    //如果要插入到头结点之前(其实不如把头结点设置成虚结点这样就不用考虑特殊情况了)
    if(pos==1)
    {
        temp->next=head;
        head->pre=temp;
        head=temp;
    }
    else{
        line *body=head;
        //要将该节点插入到第pos个，就建立一个指针指向第pos-1个
        for(int i=1;i<pos-1;i++)
        {
            body=body->next;
        }
        //插入到链表尾的情况也要特殊考虑
        if(body->next==NULL)
        {
            body->next=temp;
            temp->pre=body;
        }
        //插入到链表除首尾之外
        else{
            temp->pre=body;
            temp->next=body->next;
            body->next->pre=temp;
            body->next=temp;
        }
    }
    return head;
}

//双向链表的删除操作
/* 1.选择需要删除的节点
 * 2.选中这个节点的前一个节点
 * 3.将前一个节点的next指针指向需要删除结点的下一个
 * 4.将下一个节点的pre指针指向该节点的前一个
 * 5.释放掉该节点的内存*/
line *deleteLine(line *head,int data)//参数声明:data是要删除结点的值
{
    line *list=head;
    //遍历双向链表，找到要删除的节点
/*
    while((list->data!=data) && list)
    {
        list=list->next;
    }
    //选中这个节点的前一个节点
    if(list!=NULL)
    {
        list->pre->next=list->next;
        list->next->pre=list->pre;
        free(list);
        printf("--删除成功--");

    }
    else{
        printf("Error:节点不存在!!!");
    }
    return head;
*/
     while (list) {
        //判断是否与此元素相等
        //删除该点方法为将该结点前一结点的next指向该节点后一结点
        //同时将该结点的后一结点的pre指向该节点的前一结点
        if (list->data==data) {
            //如何要删除头结点
            if(list->pre==NULL)
            {
                head=list->next;
            }
            else{
            list->pre->next=list->next;
            }
            //如果要删除尾节点
            if(list->next==NULL)
            {list->pre->next==NULL;}
            else{
                list->next->pre=list->pre;
            }

            free(list);
            printf("--删除成功--\n");
            return head;
        }
        list=list->next;
    }
    printf("Error:没有找到该元素，没有产生删除\n");
    return head;
}

//双向链表的遍历
/* 1.利用next指针逐步向后索引*/
void printLine(line *head)
{
    line *list=head;
    int pos=1;
    while(list){
        printf("第%d个位置的值是%d\n",pos++,list->data);
        list=list->next;
    }
}
#endif //C_DOUBLELINKEDLIST_H
