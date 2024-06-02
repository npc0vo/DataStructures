//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// 计数排序函数
void countingSort(int *array, int size, int range) {
    // 创建并初始化计数数组
    int *count = (int *)calloc(range + 1, sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));

    // 统计每个元素的出现次数
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // 累计计数数组
    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    // 根据计数数组中值的累积来构建输出数组
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // 将排序后的结果复制回原数组
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    // 释放动态内存
    free(count);
    free(output);
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int max_element = 8; // 假设元素的值范围是0到max_element

    printf("排序前的数组: \n");
    printArray(array, size);

    countingSort(array, size, max_element);

    printf("排序后的数组: \n");
    printArray(array, size);
    system("pause");
    return 0;
}