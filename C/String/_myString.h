//
// Created by Npc on 2024/4/18.
//

#ifndef C__MYSTRING_H
#define C__MYSTRING_H
/*实现了各种对字符串的操作*/
#include "stdio.h"
#include<iostream>
#include<cstring>
using namespace std;
//获取字符串长度
/*循环遇到'\0'就停止*/
int _strlen(char str[])
{
    int i=0;
    for(i=0;str[i]!='\0';i++){}
    return i;
}

//获取字符位置--获取某字符首次在该字符串出现的位置
/*C语言中可以使用strchr(str,c)表示*/
int _charAt(char str[],char c){
    int i=0;
    for(i=0;str[i]!='\0'&&str[i]!=c;i++){}
    return i;
}

//拆分子串  截取字符串的第i-j个
char *_substr(char str[],int i,int j){
    int pos=0;
    char *backup;
    while(i<j){
        backup[pos++] = str[i++];
    }
    backup[pos]='\0';
    return backup;
}

//拆分子串 截取后m个
char *_suffix(char str[],int m){
    int len=0;
    for(;str[len]!='\0';len++){}
    //获取字符串总长度(避免使用其他封装函数，自行设计时可以使用strlen替代)

    printf("%d\n",len-m);

    int pos=0,i;
    char backup[500];
    for(i=len-m ;i<len ;i++){
        backup[pos++] = str[i];
    }
    backup[pos]='\0';
    return backup;
}

//拆分子串，截取前m个
char *_prefix(char str[],int m){
    int pos=0,i;
    char *backup;
    for(i=0 ;i<m ;i++){
        backup[pos++] = str[i];
    }
    backup[pos]='\0';
    return backup;
}

//字符串连接操作
char *_strcat(char dest[],char src[]){
    char * ret = dest;
    while(*dest!='\0'){dest++;}
    //将src内容复制在dest之后
    while(*src){
        *dest++ = *src++;
    }
    //在dest后面追加\0
    *dest = '\0';
    return ret;
}

//字符串比较操作
int _strcmp (char  *  src, char  *  dst)   {
    int  ret  =  0  ;
    while(  !(ret  =  *(unsigned  char  *)src  -  *(unsigned  char  *)dst)  &&  *dst)   //两个内容相减，完全相等则会得到值 0，取反即为相等
        ++src,  ++dst;
    if  (  ret  <  0  )
        ret  =  -1  ;
    else  if  (  ret  >  0  )
        ret  =  1  ;
    return ret;
}

//字符串匹配--暴力法
bool isBF(char str1[],char str2[]){
    bool flag=false;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            int pos=i;
            if( str1[pos++] != str2[j]){
                break;
            }else{
                if(j=len2-1)
                    flag=true;
            }
        }
    }
    return flag;
}
#endif //C__MYSTRING_H
