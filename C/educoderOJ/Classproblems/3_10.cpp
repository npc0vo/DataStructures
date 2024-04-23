//
// Created by Npc on 2024/3/25.
//
#include "stdio.h"
void test(int *sum){
    int x;
    scanf("%d",&x);
    if(x==0) sum=0;
    else{
        test(sum);
        sum+=x;
    }
    printf("%d",sum);
}
void test2(int *sum) {
    int x;
    int stack[1000]; // 定义一个栈，用于存储输入的值
    int top = -1; // 栈顶指针，初始化为-1

    while (1) {
        scanf("%d", &x);
        if (x == 0) {
            *sum = 0;
            break;
        } else {
            stack[++top] = x; // 将输入的值入栈
        }
    }

    while (top >= 0) {
        *sum += stack[top--]; // 将栈中的值出栈并累加到总和中
    }

    printf("%d", *sum);
}
int main()
{
    int sum=0;
    test2(&sum);
}
