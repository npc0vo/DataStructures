//
// Created by Npc on 2024/6/1.
//
#include <stdio.h>
#include "stdlib.h"
// 交换两个整数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 堆调整(下滤)函数
void shiftdown(int arr[], int n, int i) {
    int largest = i;     // 将当前节点假设为最大值
    int left = 2 * i + 1; // 左子节点下标
    int right = 2 * i + 2; // 右子节点下标

    // 如果左子节点存在且大于当前节点，更新最大值下标
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点存在且大于当前节点，更新最大值下标
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是当前节点，则交换并递归调整
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        shiftdown(arr, n, largest);
    }
}

// 堆排序主函数
void heapSort(int arr[], int n) {
    // 构建大顶堆(对每个父节点进行下滤)
    for (int i = n / 2 - 1; i >= 0; i--)
        shiftdown(arr, n, i);

    // 一个个取出元素并重新构建最大堆
    for (int i = n - 1; i >= 0; i--) {
        // 将当前堆顶（最大值）移到数组末尾
        swap(&arr[0], &arr[i]);

        // 对减少了一个元素的堆继续进行堆调整
        shiftdown(arr, i, 0);
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 主函数
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("排序后的数组: \n");
    printArray(arr, n);
    system("pause");
    return 0;
}