#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;  // 块的最大值
    int start;  // 块的起始索引
    int end;  // 块的结束索引
} IndexBlock;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int blockSearch(int arr[], IndexBlock indexTable[], int n, int blockSize, int key) {
    int blockIndex = -1;

    // 找到可能的块
    for (int i = 0; i < blockSize; i++) {
        if (key <= indexTable[i].key) {
            blockIndex = i;
            break;
        }
    }

    // 如果没有找到合适的块，则返回-1
    if (blockIndex == -1) {
        return -1;
    }

    // 在线性查找块中的元素
    for (int i = indexTable[blockIndex].start; i <= indexTable[blockIndex].end; i++) {
        if (arr[i] == key) {
            return i;  // 找到元素，返回其索引
        }
    }

    return -1;  // 未找到元素
}

int main() {
    int arr[] = {3, 7, 15, 20, 25, 29, 35, 50, 55, 65, 75, 80, 85, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int blockSize = 4;  // 块的数量

    // 创建索引块
    IndexBlock indexTable[blockSize];
    for (int i = 0; i < blockSize; i++) {
        indexTable[i].start = i * (n / blockSize);
        indexTable[i].end = (i == blockSize - 1) ? (n - 1) : ((i + 1) * (n / blockSize) - 1);
        indexTable[i].key = arr[indexTable[i].end];
    }

    // 查找键值
    int key = 50;
    int result = blockSearch(arr, indexTable, n, blockSize, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found\n", key);
    }
    system("pause");
    return 0;
}
