//
// Created by Npc on 2024/4/18.
//

#include "circularQueue.h"
int main()
{
    cir_queue *q=init();
    /*********入队操作***********/
    for(int i=0;i<=6;i++)
    {
        push(q,i);
    }
    printCirQueue(q);
    /*********出队操作***********/
    for(int i=0;i<=6;i++)
    {
        pop(q);
        printCirQueue(q);
    }
    system("pause");
    return 0;

}