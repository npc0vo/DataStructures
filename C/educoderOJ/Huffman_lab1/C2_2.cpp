
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
    char c;                    //结点的字符
    int frequency;            // 字符的频度
    char *code;            // 字符的编码(对哈夫曼树结点有效)
    struct ListNode *parent;            //结点的双T亲结点(对哈夫曼树结点有效)
    struct ListNode *left;                //结点的左子树(对哈夫曼树结点有效)
    struct ListNode *right;                // 结点的右子树(对哈夫曼树结点有效)
    struct ListNode *next;                // 结点的后继结点(对频度链表结点有效)
} ListNode, HuffmanTree;
/*frequency就相当于weight*/
/*建立HuffmanTree之前要先建立节点*/
/*首先以下是基于head是虚拟头结点的情况下考虑这样可以避免特殊情况的处理，从而简化操作*/
ListNode *createOneNode(char ch) {
    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
    temp->c = ch;
    temp->frequency = 1;
    temp->next = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

/*查找该字符是否在该链表中*/
int isInList(ListNode *head, char ch) {
    ListNode *p = head->next;
    while (p) {
        if (p->c == ch) {
            p->frequency++;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

//遍历输入的字符串，如果该字符存在已有的列表，frequency+1，否则创建该节点
ListNode *createListNode(ListNode *head, char *str) {
    int str_len = strlen(str);
    ListNode *p = head;
    //遍历每个字符
    for (int i = 0; i < str_len; i++) {
        char ch = *(str + i);
        if (isInList(head, ch)) {
            //如果找到了就默认frequency++,因此这里直接进行下一个字符的判断
            continue;
        } else {
            //采用尾插法建立链表
            while (p->next) {
                p = p->next;
                //遍历到尾节点
            }
            ListNode *newNode = createOneNode(ch);
            p->next = newNode;
        }
    }
    return head;
}

void ListTraverse(ListNode *head) {
    ListNode *p = head->next;
    while (p&&p->c!='\0') {
        /* 示例输出:   'e' 8   */  //注意换行符要进行特殊处理
        if (p->c == '\n') {
            printf("'\\n' %d %s\n", p->frequency,p->code);
        } else { printf("'%c' %d %s\n", p->c, p->frequency,p->code); }
        p = p->next;
    }
}

/*突然发现用选择排序不太符合题目要求，因为要求相同频率的节点按照输入顺序排列，所以写完选择排序我又重新写了一遍冒泡排序*/
void frequencyChoiceSort(ListNode *Head) {
    ListNode *q = Head->next;
    ListNode *prevq = Head;
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
                prevMax = prevtmp;
            }
            prevtmp = temp;
            temp = temp->next;
        }
        //如果max变化了就交换节点
        if (maxNode != q) {
            prevq->next = maxNode;
            ListNode *temp2 = q->next;
            q->next = maxNode->next;
            maxNode->next = temp2;
            prevMax->next = q;

            //由于指针发生了交换，所以p指针不再指向原来的节点
            //恢复指针指向的节点
            q = maxNode;
        }
        prevq = q;
        q = q->next;
    }
}


void frequencyBubbleSort(ListNode *Head) {
    if (Head == NULL || Head->next == NULL) {
        return;
    }
    ListNode *tail = Head;
    int length = 0;
    //获取链表长度
    while (tail->next) {
        length += 1;
        tail = tail->next;
    }

    for (int i = 0; i < length; ++i) {
        ListNode *current = Head->next;
        ListNode *prev = Head;
        while (current && current->next) {
            if (current->frequency < current->next->frequency) {
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

// 选择频率最小的两个节点
ListNode *selectMins(ListNode *head, ListNode *ignore) {
    ListNode *min1 = NULL;
    ListNode *min2 = NULL;
    ListNode *p = head->next;
    while (p) {
        if (p != ignore && (!p->parent)) {
            if (min1 == NULL || p->frequency < min1->frequency) {
                min2 = min1;
                min1 = p;
            } else if (min2 == NULL || p->frequency < min2->frequency) {
                min2 = p;
            }
        }
        p = p->next;
    }
    return min1;
}

HuffmanTree *buildHuffmanTree(ListNode *Head) {
    // 计算链表大小,并获得尾节点
    ListNode *temp = Head->next;
    ListNode *tail = Head;
    int size = 0;
    while (temp) {
        size += 1;
        tail = temp;
        temp = temp->next;
    }

    // 构建哈夫曼树
    for (int i = 1; i <= size - 1; ++i) {
        // 选择频率最小的两个节点
        ListNode *min1 = selectMins(Head, NULL);
        ListNode *min2 = selectMins(Head, min1);

        // 创建新节点，合并两个节点
        ListNode *newNode = createOneNode('\0');
        newNode->frequency = min1->frequency + min2->frequency;
        newNode->left = min1;
        min1->parent=newNode;
        newNode->right = min2;
        min2->parent=newNode;

        // 将新节点插入链表
        tail->next = newNode;
        tail = newNode;

    }
    return tail; //返回的就是root节点
}

// 递归函数，生成哈夫曼编码并存储到节点中
void generateHuffmanCodeHelper(ListNode *root, char *code, int depth) {
    if (root == NULL) {
        return;
    }

    // 遍历到叶子节点，将编码存储到节点中
    if (root->left == NULL && root->right == NULL) {
        root->code = (char *)malloc((depth + 1) * sizeof(char));
        strcpy(root->code, code);
        return;
    }

    // 左子树路径上添加 0
    code[depth] = '0';
    code[depth+1]='\0';
    generateHuffmanCodeHelper(root->left, code, depth + 1);

    // 右子树路径上添加 1
    code[depth] = '1';
    code[depth+1]='\0';
    generateHuffmanCodeHelper(root->right, code, depth + 1);
}

// 生成哈夫曼编码的函数
void generateHuffmanCode(ListNode *root) {
    // 分配内存来存储编码
    char *code = (char *)malloc(256 * sizeof(char));
    // 从根节点开始生成编码
    generateHuffmanCodeHelper(root, code, 0);
}
// 计算带权路径长度 R 的递归函数
int calculateWeightedPathLengthHelper(ListNode *root, int depth) {
    if (root == NULL) {
        return 0;
    }
    // 到达叶子节点，返回深度与频率的乘积
    if (root->left == NULL && root->right == NULL) {
        return depth * root->frequency;
    }
    // 递归计算左子树和右子树的带权路径长度，并相加
    return calculateWeightedPathLengthHelper(root->left, depth + 1) + calculateWeightedPathLengthHelper(root->right, depth + 1);
}

// 计算带权路径长度 R 的函数
int calculateWeightedPathLength(ListNode *root) {
    // 从根节点开始计算
    return calculateWeightedPathLengthHelper(root, 0);
}
int main() {
    char *str;
    int i = 0;
    char ch;

    str = (char *) malloc(sizeof(char) * 2000);//假设要读入1000个字符
    memset(str, 0, 2000);


    //读取字符串
    while ((ch = getchar()) != EOF) {
        *(str + i) = ch;
        i += 1;
    }
    //建立一个头结点
    ListNode *Head = createOneNode('0');
    createListNode(Head, str);
    frequencyBubbleSort(Head);
    ListNode *root= buildHuffmanTree(Head);
    generateHuffmanCode(root);
    ListTraverse(Head);
    printf("%d", calculateWeightedPathLength(root));
    system("pause");
    return 0;
}
//Your code end