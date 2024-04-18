//
// Created by Npc on 2024/4/18.
//

#include "LinkedStack.h"
#include "ArrayStack.h"

int main() {
    /*********先测试ArrayStack*************/
    stack *s = init();
    int input[5] = {11, 22, 33, 44, 55};
    for (int i = 0; i < 5; i++) {
        push(s, input[i]);
    }
    print_stack(s);
    ////
    pop(s);
    print_stack(s);
    /*********再测试LinkStack*************/
    LinkStack *p;
    p = CreateStack();
    int n = 5;
    int input2[6] = {10, 20, 30, 40, 50, 60};
    /////////////以依次入栈的方式创建整个栈//////////////
    for (int i = 0; i < n; i++) {
        PushStack(p, input2[i]);
    }
    show_stack(p);
    ////////////////////出栈///////////////////////
    PopStack(p);
    show_stack(p);
    system("pause");
    return 0;
}