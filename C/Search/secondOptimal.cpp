/*
//
// Created by Npc on 2024/5/30.
//
#include "stdlib.h"
#include "stdio.h"
typedef int KeyType;//定义关键字类型
typedef struct {
    KeyType key;
}ElemType; //定义元素类型

typedef struct BiTNode{
    ElemType data;
    BiTNode *lchid,*rchid;
}BiTNode,*BiTree;

int i; //每次选取的根节点的下表
int min;
int dw;

//递归创建次优查找树,R数组为查找表，sw数组为存储的各关键字的概率,low和high表示sw数组中的权值范围
void SecondOptimal(BiTree *T,ElemType R[],float sw[],int low,int high)
{
    if(low>high)
    {
        *T=NULL;
        return;
    }
    //由有序表R[low...high]及其累计权值表sw(sw[0]=0)，递归构造次优查找树
    i=low;
    min=abs(sw[high]-sw[low]);//初始化一个当前权值最大的
    dw=sw[high]+sw[low-1];
    //选择最小的△Pi值
    for(int j=low+1;j<=high;j++)//
    {
        int DPj=abs(dw-sw[j]-sw[j-1]);
        if(DPj<min)
        {
            i=j;
            min=DPj;
        }
    }

    //开始建树
    *T=(BiTree) malloc(sizeof(BiTNode));
    (*T)->data=R[i];//生成节点，第一次生成根

    SecondOptimal(&(*T)->lchid,R,sw,low,i-1);//构造左子树
    SecondOptimal(&(*T)->rchid,R,sw,i+1,high);//构造右子树
}
//中序遍历打印树节点
void InOrderTraversal(BiTree T)
{
    if(T!=NULL)
    {
        InOrderTraversal(T->lchid);
        printf("%d ",T->data.key);
        InOrderTraversal(T->rchid);
    }
}
int main() {
    // 测试数据
    ElemType R[] = { {0}, {1}, {2}, {3}, {4}, {5} }; // 假设有5个关键字，从1到5
    float sw[] = { 0, 2, 4, 6, 8, 10, 12 }; // 对应的权值

    int n = sizeof(R) / sizeof(R[0]) - 1; // 关键字数量

    BiTree T;
    SecondOptimal(&T, R, sw, 1, n); // 构建次优查找树

    printf("InOrder traversal of the constructed SOST: ");
    InOrderTraversal(T);
    printf("\n");
    system("pause");
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int KeyType; // 定义关键字类型

typedef struct {
    KeyType key;
} ElemType; // 定义元素类型

typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

// 创建次优查找树
void SecondOptimal(BiTree* T, ElemType R[], float sw[], int low, int high) {
    if (low > high) {
        *T = NULL;
        return;
    }

    int i = low;
    int min = abs((int)(sw[high] - sw[low]));
    int dw = (int)(sw[high] + sw[low - 1]);

    // 选择最小的△Pi值
    for (int j = low + 1; j <= high; j++) {
        int diff = abs(dw - (int)(sw[j] + sw[j - 1]));
        if (diff < min) {
            i = j;
            min = diff;
        }
    }

    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = R[i]; // 生成结点（第一次生成根）
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;

    // 确保左、右子树被正确创建
    SecondOptimal(&((*T)->lchild), R, sw, low, i - 1); // 构造左子树
    SecondOptimal(&((*T)->rchild), R, sw, i + 1, high); // 构造右子树
}

// 中序遍历打印树节点
void InOrderTraversal(BiTree T) {
    if (T != NULL) {
        InOrderTraversal(T->lchild);
        printf("%d ", T->data.key);
        InOrderTraversal(T->rchild);
    }
}

int main() {
    // 测试数据
    ElemType R[] = { {0}, {1}, {2}, {3}, {4}, {5} }; // 假设有5个关键字，从1到5
    float sw[] = { 0, 2, 4, 6, 8, 10, 12 }; // 对应的权值

    int n = sizeof(R) / sizeof(R[0]) - 1; // 关键字数量

    BiTree T;
    SecondOptimal(&T, R, sw, 1, n); // 构建次优查找树

    printf("InOrder traversal of the constructed SOST: ");
    InOrderTraversal(T);
    printf("\n");
    system("pause");
    return 0;
}


