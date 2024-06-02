//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 将节点插入到链表中
void insertIntoSortedList(struct ListNode** head, struct ListNode* newNode) {
    struct ListNode* current;

    // 如果链表为空或新节点应该成为新的头节点
    if (*head == NULL || (*head)->val >= newNode->val) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        // 找到新节点应该插入的位置
        while (current->next != NULL && current->next->val < newNode->val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 表插入排序
void listInsertionSort(int arr[], int n) {
    struct ListNode* sortedList = NULL;

    // 遍历数组，将元素插入到链表中
    for (int i = 0; i < n; i++) {
        struct ListNode* newNode = createNode(arr[i]);
        insertIntoSortedList(&sortedList, newNode);
    }

    // 将排序好的链表内容复制回数组
    struct ListNode* current = sortedList;
    int index = 0;
    while (current != NULL) {
        arr[index++] = current->val;
        struct ListNode* temp = current;
        current = current->next;
        free(temp);  // 释放节点
    }
}

// 辅助函数：打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组:\n");
    printArray(arr, n);

    listInsertionSort(arr, n);

    printf("排序后的数组:\n");
    printArray(arr, n);

    system("pause");
    return 0;
}