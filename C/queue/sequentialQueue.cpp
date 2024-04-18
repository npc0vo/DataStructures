//
// Created by Npc on 2024/4/18.
//

#include "sequentialQueue.h"
int main()
{
    queue *q=initQueue();
    printf("入队:\n");
    for(int i=1;i<=5;i++)
    {
        push(q,i);
        print_queue(q);
    }

    printf("出队\n");
    for(int i=1;i<=5;i++)
    {
        pop(q);
        print_queue(q);
    }
    system("pause");
    return 0;
}