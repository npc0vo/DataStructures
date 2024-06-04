//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建一个新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 链表追加节点
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 将桶链表的内容合并到数组中
void collectBuckets(Node** buckets, int arr[], int n) {
    int i, j;
    int index = 0;
    for (i = 0; i < 10; ++i) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        buckets[i] = NULL;
    }
}

// 获取数组中最大的元素
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 基数排序函数（链式基数排序）
void radixSort(int arr[], int n) {
    // 创建桶链表数组
    Node* buckets[10] = {NULL};

    // 找到最大值以决定最高位数
    int max = getMax(arr, n);
    int exp;

    // 逐位分配和收集
    for (exp = 1; max / exp > 0; exp *= 10) {
        // 将数组元素分配到桶中
        for (int i = 0; i < n; ++i) {
            int bucketIndex = (arr[i] / exp) % 10;
            appendNode(&buckets[bucketIndex], arr[i]);
        }

        // 收集桶中的元素到数组中
        collectBuckets(buckets, arr, n);
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("排序后的数组: \n");
    printArray(arr, n);
    system("pause");
    return 0;
}