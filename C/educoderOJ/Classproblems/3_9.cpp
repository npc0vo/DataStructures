//
// Created by Npc on 2024/3/25.
//
#include <stdio.h>
void ditui(int n){
    int i;
    i=n;
    while(i>1){
        printf("%d",i--);
    }
}
void digui(int n){
    int i;
    i=n;
    if(i<=1)
    {
        return;
    }
    printf("%d",i);
    digui(n-1);
}
int main()
{
    ditui(5);
    digui(5);
}