#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char c;
    int frequency;
    int idx;
    char code[100];
    struct ListNode *parent;
    struct ListNode *left;
    struct ListNode *right;
    struct ListNode *next;
} ListNode, HuffmanTree;
//结构体 ListNode为链表结构体，HuffmanTree为哈夫曼树结构体 
ListNode* create_node(char ch) {
    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->c = ch;
    new_node->frequency = 1;
    new_node->next = NULL;
    return new_node;
}
//结点创建函数，创建一个结点 
ListNode* find_or_create(ListNode* head, char ch) {
    if (!head) {
        return create_node(ch);
    }
    ListNode* curr = head;
    while (curr) {
        if (curr->c == ch) {
            curr->frequency += 1;
            return head;
        }
        curr = curr->next;
    }
    ListNode* new_node = create_node(ch);
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = new_node;
    return head;
}
//该函数沿着头节点开始遍历，如果结点已经存在，频度加一，否则创建该节点。返回头节点 
void sort1(ListNode** head) {
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return;
    }
    ListNode* tail = NULL;
    do {
        ListNode* pre = *head;
        ListNode* cur = pre->next;
        while (cur != tail) {
            if (pre->frequency < cur->frequency) {
                ListNode* tmp = pre->next;
                pre->next = cur->next;
                cur->next = pre;
                if (pre == *head) {
                    *head = cur;
                } else {
                    ListNode* pre_pre = *head;
                    while (pre_pre->next != pre) {
                        pre_pre = pre_pre->next;
                    }
                    pre_pre->next = cur;
                }
                pre = cur;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        tail = pre;
    } while (*head != tail);
}
//sort1函数，对单链表进行降序，与sort函数同，因为输出顺序要按照第一关（降序输出） 
int main() {
    ListNode* head = NULL;
    int sum=0;
    char ch;
    while ((ch = getchar()) != EOF) {
    	
        head = find_or_create(head, ch);
    }
    sort1(&head);
    ListNode* p=head;
    while(p)
	{
		if(p->c!='\n')
		{
			printf("'%c' %d\n",p->c,p->frequency);
			sum+=strlen(p->code)*(p->frequency);
			p=p->next;
		}
		else{
			printf("'\\n' %d\n",p->frequency);
			sum+=strlen(p->code)*(p->frequency);
			p=p->next;
		}
	}
    system("pause");
    return 0;
}