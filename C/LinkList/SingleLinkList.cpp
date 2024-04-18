//
// Created by Npc on 2024/4/17.
//

/*
测试文件
 */


/*
#include "SingleLinkList.h"
#include "stdio.h"
int main()
{
    printf("HelloWorld");
    //创建链表测试
    LinkedList list;
    printf("please input the data\n");
    list=LinkedListCreateT();
    printList(list);

    //插入
    int i;
    int x;
    printf("请输入插入数据的位置");
    scanf("%d",&i);
    printf("请输入插入该位置的值:");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);

    //修改
    printf("请输入修改数据的位置:");
    scanf("%d",&i);
    printf("请输入修改该位置的值:");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);

    //删除
    printf("请输入要删除数据的值");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);


    return 0;

}*/
#include "SingleLinkList.h"

int main() {
    //创建3

    LinkedList list;
    printf("请输入单链表的数据：以EOF结尾\n");
    list = LinkedListCreatT();
    //list=LinkedListCreatT();
    printList(list);

    //插入
    int i;
    int x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);

    LinkedListInsert(list,i,x);
    printList(list);

    //修改
    printf("请输入修改的数据：");
    scanf("%d",&i);
    printf("请输入修改后的值：");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);

    //删除
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);

    return 0;
}