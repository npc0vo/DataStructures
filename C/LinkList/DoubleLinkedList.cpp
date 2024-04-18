//
// Created by Npc on 2024/4/17.
//

#include "DoubleLinkedList.h"
int main()
{
    line *head=NULL;
    printf("创建双链表操作\n");
    head=initLine(head);
    printLine(head);
    //CreateLine
    printf("插入操作\n");
    head= insertLine(head,3,2);
    printLine(head);
    //InsertLine
    printf("删除操作\n");
    head= deleteLine(head,3);
    printLine(head);
    //DeleteLine
    system("pause");
    return 0;

}