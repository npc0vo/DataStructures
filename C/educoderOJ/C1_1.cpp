//
// Created by Npc on 2024/4/9.
//
/*编程要求
根据提示，在右侧编辑器补充代码，程序会自己调用你所填写的函数。
函数insertTail：链表尾部插入；
    参数：h-链表头指针，t-指向要插入的结点；
    返回值：插入结点后链表的首结点地址。
函数delnode:删除指定数值；
    参数：h-链表表头指针，e指定节点的数值；
    如果该数值的节点存在，就删除节点，否则打印“error”。*/

#include "linearList.h"
#include <stdio.h>
#include "stdlib.h"
node *insertTail(node *h, node *t)
{
    // 请在此添加代码，补全函数insertTail
    /********** Begin *********/
    node* temp=h;
    //极端情况的处理
    if(h==NULL)
    {
        return t;
    }
    while(temp->next)
    {
        temp=temp->next;//将temp指针指到尾部
    }
    //此时temp指向尾指针
    temp->next=t; //尾部指针进行插入
    return h;
    /********** End **********/
}
void delNode(node* h,int e)
{
	//清在此添加代码，补全函数delnode
	/********** Begin *********/
    //处理极端情况
    if(h==NULL)
    {
        printf("error\n");
        return;
    }
    node* prev = NULL;
    node* curr = h;

    while (curr != NULL && curr->data != e) {
        prev = curr;
        curr = curr->next;
    }
    if(curr)
    {
        prev->next=curr->next;
        free(curr);
    }
    else
        printf("error\n");
    /********** End **********/
}