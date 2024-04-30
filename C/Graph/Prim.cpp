//
// Created by Npc on 2024/4/25.
//

#include "Prim.h"
int main() {
    adjmatrix GA;
    Edge GE[n*(n-1)/2], T[n];
    createAdjMatrix(GA);
    InitEdge(GE,arcnum);
    GetEdgeSet(GA,GE);
    SortEdge(GE,arcnum);
    Prim(GA,T);
    printf("\n");
    OutEdge(T,n-1);
    system("pause");
    return 0;
}