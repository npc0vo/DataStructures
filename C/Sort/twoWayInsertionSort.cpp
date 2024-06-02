#include <stdio.h>
#include <stdlib.h>

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 二路插入排序实现
void twoWayInsertionSort(int arr[], int size) {
    // 临时数组来存储排序结果
    int *temp = (int *)malloc(size * sizeof(int));
    int start = 0, end = 0; // 临时数组的起始和结束索引

    temp[0] = arr[0]; // 初始化第一个元素
    for (int i = 1; i < size; i++) {
        if (arr[i] < temp[start]) {
            // 插入到temp的起始位置前
            start = (start - 1 + size) % size;
            temp[start] = arr[i];
        } else if (arr[i] > temp[end]) {
            // 插入到temp的结束位置后
            end = (end + 1) % size;
            temp[end] = arr[i];
        } else {
            // 插入到temp的中间位置
            int j = end;
            // 向右移动元素以腾出空间
            while (arr[i] < temp[j]) {
                temp[(j + 1) % size] = temp[j];
                j = (j - 1 + size) % size;
            }
            temp[(j + 1) % size] = arr[i];
            end = (end + 1) % size;
        }
    }

    // 将排序后的元素拷贝回原数组
    for (int i = 0; i < size; i++) {
        arr[i] = temp[(start + i) % size];
    }

    // 释放临时数组内存
    free(temp);
}

int main() {
    int arr[] = {22, 11, 99, 88, 9, 7, 42};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    twoWayInsertionSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    system("pause");
    return 0;
}
