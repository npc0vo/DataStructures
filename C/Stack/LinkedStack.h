//
// Created by Npc on 2024/4/18.
//

#ifndef C_LINKEDSTACK_H
#define C_LINKEDSTACK_H

#include "stdio.h"
#include "stdlib.h"
/*栈分为数组栈和链表栈，其区别是数组栈使用数组进行功能的模拟，
 * 实现较为快速和便利，而链表栈使用链表的思路去设计，实现较为麻烦，但是其稳定不易出错；在链表栈中又分为静态链表栈和动态链表栈，静态链表栈给定栈的空间大小，
 * 不允许超过存储超过给定数据大小的元素，而动态栈使用的是自动创建空间的方法进行创建，
 * 只要符合机器的硬件要求以及编译器的控制，其理论上是极大的。*/
//栈结点设计
/*其中data表示数据，其可以是简单的类型
 * （如int,double等等），
 * 也可以是复杂的结构体（struct类型）；*/
typedef struct node {
    int data;
    struct node *next;
} node;
/*限制性的设计，额外添加一个结构体，其包括了一个永远指向栈头的指针top和一个计数器count记录元素个数，
 * （也可以设计成一个指针top和一个指针bottom分别指向栈头和栈尾）
 * 其主要功效就是设定允许操作元素的指针以及确定栈何时为空*/
typedef struct Stack {
    node *top;
    int count;
} LinkStack;

//创建栈
LinkStack *CreateStack() {
    LinkStack *p;
    p = (LinkStack *) malloc(sizeof(LinkStack));
    if (p == NULL) {
        printf("创建失败");
        exit(0);
    }
    p->count = 0;
    p->top = NULL;
    return p;
}

//入栈操作
LinkStack *PushStack(LinkStack *p, int elem) {
    //处理栈没开辟成功的特殊情况
    if (p == NULL) {
        return NULL;
    }
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->data = elem;
    temp->next = p->top;
    p->top = temp;
    p->count++;
    return p;
}

//出栈操作
LinkStack *PopStack(LinkStack *p) {
    node *temp;
    temp = p->top;
    if (p->top == NULL) {
        printf("错误，栈为空");
    } else {
        p->top = p->top->next;
        free(temp);
        //delete temp
        p->count--;
        return p;
    }
}

//栈的遍历:输出栈的所有元素
int show_stack(LinkStack *p) {
    node *temp;
    temp = p->top;
    if (p->top == NULL) {
        printf("错误，栈为空");
        return 0;
    }
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

#endif //C_LINKEDSTACK_H
