//
// Created by Npc on 2024/4/9.
//
/*设置一个栈，当读到左括号时，左括号进栈。当读到右括号时，则从栈中弹出一个元素，与读到的左括号进行匹配，若匹配成功，继续读入；否则匹配失败。另外，在算法的开始和结束时，栈都应该是空的，所以匹配到最后还要判断栈是否为空，若空，则说明匹配成功，返回1。若非空，则说明匹配失败，返回0。

步骤如下：

设置一个链栈st，定义一个整型flag变量（初始为1）。

用i扫描表达式exp，当i<n并且flag=1时循环：

当遇到左括号“(”、“[”、“{”时，将其进栈；

遇到“}”、“]”、“)”时，出栈字符ch，若出栈失败（下溢出）或者ch不匹配，则置flag=0退出循环;

否则直到exp扫描完毕为止。

若栈空并且flag为1则返回1，否则返回0。*/
#include "slink.h"

bool check(char *str) {
    int flag = 1;
    sqstack st;
    char ch;
    initstack(st);
    for (int i = 0; i < MAXSIZE; i++) {
        char b = *(str + i);
        if (b == '(' || b == '[' || b == '{') {
            push(st, b);
            continue;
        }
        ch = st.data[st.top];
        if (b == ')') {
            if (ch != '(') {
                flag = 0;
                return false;
            }
            pop(st, ch);
        }
        if (b == ']') {
            if (ch != '[') {
                flag = 0;
                return false;
            }
            pop(st, ch);
        }
        if (b == '}') {
            if (ch != '{') {
                flag = 0;
                return false;
            }
            pop(st, ch);
        }

    }
     if (isempty(st) && flag) {
            return true;
        } else
            return false;
}
