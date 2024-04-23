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
//结构体
ListNode* create_node(char ch) {
    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->c = ch;
    new_node->frequency = 1;
    new_node->next = NULL;
    return new_node;
}//结点创建函数
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

//查找or创建结点




void sort(ListNode** head) {
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return;
    }
    ListNode* tail = NULL;
    do {
        ListNode* pre = *head;
        ListNode* cur = pre->next;
        while (cur != tail) {
            if (pre->frequency > cur->frequency) {
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
//对结点进行排序
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

HuffmanTree* huffman_tree(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    ListNode* p = head;
    ListNode* assist_head = NULL;
    while (p) {
        ListNode* assist_node = (ListNode*)malloc(sizeof(ListNode));
        assist_node->c = p->c;
        
        assist_node->frequency = p->frequency;
        assist_node->next = NULL;
        assist_node->left = NULL;
        assist_node->right = NULL;
        if (assist_head == NULL) {
            assist_head = assist_node;
        } else {
            ListNode* q = assist_head;
            while (q->next) {
                q = q->next;
            }
            q->next = assist_node;
        }
        
        p = p->next;
    }
    
    HuffmanTree* tree = NULL;
    while (assist_head->next) {
        ListNode* p1 = assist_head;
        
        ListNode* p2 = p1->next;
        assist_head = p2->next;
        ListNode* assist_node = (ListNode*)malloc(sizeof(ListNode));
        assist_node->c = '\0';
        assist_node->frequency = p1->frequency + p2->frequency;
        assist_node->next = NULL;
        assist_node->left = p1;
        assist_node->right = p2;
        p1->next = NULL;
        p2->next = NULL;
        if (assist_head == NULL) {
            tree = (HuffmanTree*)malloc(sizeof(HuffmanTree));
            tree->c = '\0';
            tree->frequency = assist_node->frequency;
            tree->left = assist_node->left;
            tree->right = assist_node->right;
            free(assist_node);
            return tree;
        } else {
            ListNode* q = assist_head;
            while (q->next) {
                q = q->next;
            }
            q->next = assist_node;
            sort(&assist_head);
        }
    }
    tree = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    tree->c = assist_head->c;
  	printf("%c",tree->c);
    tree->frequency = assist_head->frequency;
    tree->left = assist_head->left;
    tree->right = assist_head->right;
    free(assist_head);
    return tree;
}
//哈夫曼树的建立，选取最小和次小结点，相加得到根结点，这里利用辅助链表进行创建，为了保持原有链表数据的有序性  之前在原有链表进行操作，由于新建结点也会插入在链表中，最后输出时有叶子节点之和的未知值

void print_code(HuffmanTree** root, char* code, int top) {
    if ((*root)->left) {
        code[top] = '0';
        code[top+1]='\0';
        print_code(&((*root)->left), code, top + 1);
        
    }
    if ((*root)->right) {
        code[top] = '1';
        code[top+1]='\0';
        print_code(&((*root)->right), code, top + 1);
    }
    if (!((*root)->left) && !((*root)->right)) {
        
    	strcpy((*root)->code,code);
        
    }
}
//递归调用函数进行哈夫曼编码，同时把编码传入到哈夫曼树数据结构中
void printleaf(HuffmanTree* root,ListNode** L)
{	
	if(root!=NULL)
	{
	if(root->left==NULL&&root->right==NULL&&root->c==(*L)->c)
	{	
		
		strcpy((*L)->code,root->code);
	}
	
	printleaf(root->left,L);
	printleaf(root->right,L);
	}
}
//将哈夫曼树叶子节点的编码传到单链表中
int main() {
    ListNode* head = NULL;
    int sum=0;
    char ch;
    char code[10000];
    char str[10000];
    char codee[99999];
    int i=0;
    while ((ch = getchar()) != EOF) {
    	str[i++]=ch;
        head = find_or_create(head, ch);
    }
    
    
    sort(&head);
    ListNode* p=head;
    
    
 	HuffmanTree* root;
 	root=huffman_tree(head);
 	root->parent=NULL;
 	print_code(&root,code,0);
 	while(p)
 	{
 		printleaf(root,&p);
 		p=p->next;
	}
	sort1(&head);
	p=head;
	while(p)
	{
		if(p->c!='\n')
		{
			printf("'%c' %d %s\n",p->c,p->frequency,p->code);
			sum+=strlen(p->code)*(p->frequency);
			p=p->next;
		}
		else{
			printf("'\\n' %d %s\n",p->frequency,p->code);
			sum+=strlen(p->code)*(p->frequency);
			p=p->next;
		}
	}
	printf("%d",sum);	
	
}
