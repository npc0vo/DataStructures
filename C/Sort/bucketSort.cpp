//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体
struct Node {
    float data;
    struct Node* next;
};

// 创建一个新的节点
struct Node* createNode(float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 插入节点到链表中
void insertNode(struct Node** head, float value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 打印链表
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%f ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 桶排序函数
void bucketSort(float array[], int n) {
    // 1. 创建桶（链表数组）
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. 分配数组中的元素到各个桶
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * array[i]);
        insertNode(&buckets[bucketIndex], array[i]);
    }

    // 3. 合并所有桶中的元素
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            array[index++] = current->data;
            current = current->next;
        }
    }

    // 4. 释放桶内存
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

// 打印数组
void printArray(float array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

int main() {
    float array[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int size = sizeof(array) / sizeof(array[0]);

    printf("排序前的数组: \n");
    printArray(array, size);

    bucketSort(array, size);

    printf("排序后的数组: \n");
    printArray(array, size);
    system("pause");
    return 0;
}