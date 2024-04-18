//
// Created by Npc on 2024/4/18.
//

#include "CircularLinkedList.h"
int main(){
    //////////初始化头结点//////////////
    list *head=initlist();
    head->next=head;
    ////////通过插入元素完善链表/////////
    for(int i=0;i<5;i++){   //只是演示使用，不具体提供输入
        create_list(head);
    }
    display(head);
    ////////////插入元素////////////////
    head=insert_list(head,1,10);
    display(head);
    ////////////删除元素////////////////
    delete_list(head);
    display(head);
    system("pause");
    return 0;
}