//
// Created by Npc on 2024/3/25.
//
#include "stdio.h"
int main()
{
    int a[9][3][5][8];
    char* p=&a[0][0][0][0];
    char* p1=&a[1][1][1][1];
    char* p2=&a[3][1][2][5];
    char* p3=&a[8][2][4][7];
    printf("%d\n",p1-p+100);
    printf("%d\n",p2-p+100);
    printf("%d\n",p3-p+100);
}