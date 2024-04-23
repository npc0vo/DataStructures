//
// Created by Npc on 2024/4/9.
//

#ifndef C_LINEARLIST_H
#define C_LINEARLIST_H
typedef struct node
{
    int data;  // 数据域
    struct node * next;  //指针域,指向下一个结点
}node;
#endif //C_LINEARLIST_H
