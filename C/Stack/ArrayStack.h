//
// Created by Npc on 2024/4/18.
//

#ifndef C_ARRAYSTACK_H
#define C_ARRAYSTACK_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define maxn 1000
typedef struct stack {
    int data[maxn];
    int top;
} stack;

//栈的初始化
stack *init() {
    stack *s = (stack *) malloc(sizeof(stack));
    if (s == NULL) {
        printf("开辟栈空间失败!");
        exit(0);
    }
    memset(s->data, 0, sizeof(s->data));
    //memset操作来自于库文件string.h，其表示将整个空间进行初始化
    s->top = 0;
    //注意top指针指向栈顶元素的上一个
    return s;
}

//入栈push
void push(stack *s, int data) {
    s->data[s->top] = data;
    s->top++;
}

//出栈pop
void pop(stack *s) {
    if (s->top != 0) {
        s->top--;
        s->data[s->top] = 0;
    }
}

//遍历栈中元素并打印
void print_stack(stack *s) {
    for (int n = s->top - 1; n >= 0; n--) {
        printf("%d\t", s->data[n]);
    }
    printf("\n");
}

#endif //C_ARRAYSTACK_H
