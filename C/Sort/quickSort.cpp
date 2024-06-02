//
// Created by Npc on 2024/6/1.
//
#include <stdio.h>
#include "stdlib.h"
// 交换两个整数值的宏定义
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

// 分区函数，通过选定一个基准点，将数组分区
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准点
    int i = low - 1; // i 是小于基准值的子数组的最后一个元素的索引

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            SWAP(arr[i], arr[j], int); // 将小于基准值的元素移到前面
        }
    }
    SWAP(arr[i + 1], arr[high], int); // 将基准值放到正确的位置
    return i + 1; // 返回基准值的索引
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 分区索引

        quickSort(arr, low, pi - 1); // 递归排序基准值左边的子数组
        quickSort(arr, pi + 1, high); // 递归排序基准值右边的子数组
    }
}

// 打印数组函数
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("排序后的数组:\n");
    printArray(arr, n);
    system("dir");
    system("pause");
    return 0;
}