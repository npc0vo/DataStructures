//
// Created by Npc on 2024/4/28.
//

#include "Kruskal.h"
int main()
{
    MGraph G;
    CreateGraph(&G);
    Kruskal(&G);
    system("pause");
    return 0;
}