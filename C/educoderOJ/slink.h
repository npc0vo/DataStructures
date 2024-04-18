//
// Created by Npc on 2024/4/9.
//

#ifndef C_SLINK_H
#define C_SLINK_H
#include "stdio.h"
#define MAXSIZE 30

typedef struct{
	char data[30];
	int top;
}sqstack;

void initstack(sqstack &S);
bool push(sqstack &S,char x);
bool pop(sqstack &S,char &x);
bool isempty(sqstack S);
bool check(char *str);
void initstack(sqstack &S){
	S.top=-1;
}

bool push(sqstack &S,char x){
	if(S.top==MAXSIZE-1)
		return false;
	S.data[++S.top]=x;
	return true;
}

bool pop(sqstack &S,char &x){
	if(S.top==-1)
		return false;
	x=S.data[S.top--];
	return true;
}

bool isempty(sqstack S) {
	if(S.top==-1)
		return true;
	else
		return false;
}
#endif //C_SLINK_H
