//
// Created by Npc on 2024/4/9.
//
//Your code begin.
//示例仅供参考，你也可以自行修改设计
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
/*1.本关任务：建立频度链表来统计字符的频度。*/
/*2.建立单链表,若字符在频度链表中存在，则该字符的频度加1，否则创建新结点并将该结点插入到频度链表中*/
/*3.单链表排序,对所得到的频度链表进行排序，使得字符的频度按从高到低排列*/
/*测试输入：
hello world!
预期输出：
'l' 3
'o' 2
'h' 1
'e' 1
' ' 1
'w' 1
'r' 1
'd' 1
'!' 1

测试输入：
Data structure experiment
HuffmanTree
metro line
预期输出：
'e' 8
't' 5
'r' 5
'a' 3
' ' 3
'u' 3
'm' 3
'n' 3
'i' 2
'\n' 2
'f' 2
'D' 1
's' 1
'c' 1
'x' 1
'p' 1
'H' 1
'T' 1
'o' 1
'l' 1*/
/*提示：
1.字符按频度从高到低排列，相同频度的字符按输入先后进行排列，先输入的字符排列在前，后输入的字符排列在后
2.输出示例为'字符' 频度，字符和频度之间有一个空格，输出完一个字符和频度后换行再输出下一个字符和频度
3.换行符字符输出示例'\n' 10
4.最后一个字符和频度输出完后仍有一个换行符要输出*/
typedef struct ListNode            //结点结构，哈夫曼树与频度链表共用
{
    char      c;                    //结点的字符
    int      frequency;            // 字符的频度
    char     *code;            // 字符的编码(对哈夫曼树结点有效)
    struct ListNode *parent;            //结点的双T亲结点(对哈夫曼树结点有效)
    struct ListNode *left;                //结点的左子树(对哈夫曼树结点有效)
    struct ListNode *right;                // 结点的右子树(对哈夫曼树结点有效)
    struct ListNode *next;                // 结点的后继结点(对频度链表结点有效)
}ListNode,HuffmanTree;
/*frequency就相当于weight*/
/*建立HuffmanTree之前要先建立节点*/
/*首先以下是基于head是虚拟头结点的情况下考虑这样可以避免特殊情况的处理，从而简化操作*/
ListNode* createOneNode(char ch)
{
    ListNode *temp= (ListNode *) malloc(sizeof(ListNode));
    temp->c=ch;
    temp->frequency=1;
    temp->next=NULL;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}
/*查找该字符是否在该链表中*/
int isInList(ListNode *head,char ch)
{
    ListNode *p=head->next;
    while(p)
    {
        if(p->c==ch)
        {
            p->frequency++;
            return 1;
        }
        p=p->next;
    }
    return 0;
}
//遍历输入的字符串，如果该字符存在已有的列表，frequency+1，否则创建该节点
ListNode *createListNode(ListNode *head, char *str) {
    int str_len = strlen(str);
    ListNode *p=head;
    //遍历每个字符
    for(int i=0;i<str_len;i++)
    {
        char ch=*(str+i);
        if(isInList(head,ch))
        {
            //如果找到了就默认frequency++,因此这里直接进行下一个字符的判断
            continue;
        }
        else{
            //采用尾插法建立链表
            while(p->next)
            {
                p=p->next;
                //遍历到尾节点
            }
            ListNode *newNode= createOneNode(ch);
            p->next=newNode;
        }
    }
    return head;
}

void ListTraverse(ListNode *head)
{
    ListNode *p=head->next;
    while(p)
    {
        /* 示例输出:   'e' 8   */  //注意换行符要进行特殊处理
        if(p->c=='\n')
        {
            printf("'\\n' %d\n",p->frequency);
        }
        else{printf("'%c' %d\n",p->c,p->frequency);}
        p=p->next;
    }
}

/*突然发现用选择排序不太符合题目要求，因为要求相同频率的节点按照输入顺序排列，所以写完选择排序我又重新写了一遍冒泡排序*/
void frequencyChoiceSort(ListNode* Head) {
    ListNode *q = Head->next;
    ListNode *prevq =Head;
    // 利用选择排序，交换指针
    while (q) { // 终止条件：q遍历完毕
        int max = q->frequency;
        ListNode *maxNode = q;
        ListNode *temp = q->next; //  用于遍历剩余节点
        ListNode *prevtmp = q->next; // 用于保存temp的前一个节点
        ListNode *prevMax = q; // 用于保存需要交换的节点的前一个节点

        while (temp) {
            if (temp->frequency > max) {
                max = temp->frequency;
                maxNode = temp;
                prevMax=prevtmp;
            }
            prevtmp = temp;
            temp = temp->next;
        }
        //如果max变化了就交换节点
        if(maxNode!=q)
        {
            prevq->next=maxNode;
            ListNode *temp2=q->next;
            q->next=maxNode->next;
            maxNode->next=temp2;
            prevMax->next=q;

            //由于指针发生了交换，所以p指针不再指向原来的节点
            //恢复指针指向的节点
            q = maxNode;
        }
        prevq=q;
        q = q->next;
    }
}


void frequencyBubbleSort(ListNode *Head)
{
    ListNode *tail=Head;
    int length=0;
    //获取链表长度
    while(tail->next)
    {
        length+=1;
        tail=tail->next;
    }

    for (int i = 0; i < length; ++i)
    {
        ListNode *current = Head->next;
        ListNode *prev = Head;
        while (current && current->next)
        {
            if (current->frequency < current->next->frequency)
            {
                // 交换节点
                prev->next = current->next;
                current->next = current->next->next;
                prev->next->next = current;
            }
            prev = prev->next;
            current = prev->next;
        }
    }
}


int main()
{


    char *str;
    int i=0;
    char ch;

    str= (char *) malloc(sizeof(char)*2000);//假设要读入1000个字符
    memset(str, 0, 2000);


    //读取字符串
    while((ch=getchar())!=EOF)
    {
        *(str+i)=ch;
        i+=1;
    }
    //建立一个头结点
    ListNode *Head= createOneNode('0');
    createListNode(Head,str);
    frequencyBubbleSort(Head);
    ListTraverse(Head);
    system("pause");
    return 0;

}
//Your code end.
