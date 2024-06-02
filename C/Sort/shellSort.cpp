//
// Created by Npc on 2024/5/29.
//
#include <stdio.h>
#include "stdlib.h"
// 希尔排序算法
void shellSort(int arr[], int n) {
    // 开始步长为数组长度的一半，并在每一轮将步长减半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 从当前步长位置开始，对步长分组进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // 插入排序，对当前分组进行排序
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 辅助函数：打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 主函数
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("排序后的数组:\n");
    printArray(arr, n);
    system("pause");
    return 0;
}