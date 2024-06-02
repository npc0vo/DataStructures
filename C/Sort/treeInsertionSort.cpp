//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 初始化比赛树
void initializeTree(int tree[], int data[], int n) {
    // 将数据放入叶子结点
    for (int i = 0; i < n; i++) {
        tree[n + i] = data[i];
    }

    // 构建比赛树
    for (int i = n - 1; i > 0; i--) {
        tree[i] = (tree[2 * i] < tree[2 * i + 1]) ? tree[2 * i] : tree[2 * i + 1];
    }
}

// 调整比赛树
void adjustTree(int tree[], int n, int index) {
    // 将叶子结点设为无穷大
    tree[index] = INT_MAX;

    // 向上调整树结构
    while (index > 1) {
        int sibling = (index % 2) ? index - 1 : index + 1;
        int parent = index / 2;
        tree[parent] = (tree[index] < tree[sibling]) ? tree[index] : tree[sibling];
        index = parent;
    }
}

// 树形选择排序
void treeSelectionSort(int data[], int n) {
    // 使用2 * n大小的数组来模拟完全二叉树
    int size = 2 * n;
    int* tree = (int *)malloc(size * sizeof(int));
    if (!tree) {
        printf("Memory allocation error\n");
        return;
    }

    // 初始化比赛树
    initializeTree(tree, data, n);

    // 重复找到最小值并调整树
    for (int i = 0; i < n; i++) {
        // 根节点是当前最小值
        data[i] = tree[1];

        // 找到最小值在叶子节点的位置并调整树
        for (int j = n; j < size; j++) {
            if (tree[j] == data[i]) {
                adjustTree(tree, n, j);
                break;
            }
        }
    }

    // 释放内存
    free(tree);
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组:\n");
    printArray(arr, n);

    treeSelectionSort(arr, n);

    printf("排序后的数组:\n");
    printArray(arr, n);

    return 0;
}
