//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

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

// 对数组的指定位置（位）进行计数排序
void countSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int)); // 输出数组
    int i, count[10] = {0};

    // 计算每个位数字出现的次数
    for (i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // 累积计数
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 根据计数数组构建输出数组
    for (i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // 将排序后的结果复制回原数组
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// 基数排序函数
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);  // 得到数组中的最大数

    // 从最低有效位到最高有效位，对数组进行排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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

    return 0;
}