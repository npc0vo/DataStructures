//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include "stdlib.h"
// 合并两个已排序的子数组
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int L[n1], R[n2];

    // 将数据复制到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组到原始数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素（如果有）
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序函数
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 找到中点
        int mid = left + (right - left) / 2;

        // 对左半部分进行排序
        mergeSort(arr, left, mid);
        // 对右半部分进行排序
        mergeSort(arr, mid + 1, right);

        // 合并已排序的部分
        merge(arr, left, mid, right);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组:\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("排序后的数组:\n");
    printArray(arr, arr_size);
    system("pause");
    return 0;
}