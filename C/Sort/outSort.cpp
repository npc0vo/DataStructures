//
// Created by Npc on 2024/6/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define CHUNK_SIZE 100  // 每次读取的块大小
#define K 10  // 败者树的路数

typedef struct {
    int value;
    int fromRun;
} Node;

void generateTestFile(const char* filename, int numElements) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    srand((unsigned)time(NULL));
    for (int i = 0; i < numElements; i++) {
        int num = rand() % 10000;  // 生成0到9999之间的随机数
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void initialSortAndSave(const char* inputFilename, int* numChunks) {
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    int* buffer = (int*)malloc(CHUNK_SIZE * sizeof(int));
    int chunkIndex = 0;

    while (!feof(inputFile)) {
        int count = 0;
        for (int i = 0; i < CHUNK_SIZE && fscanf(inputFile, "%d", &buffer[count]) == 1; i++) {
            count++;
        }

        if (count > 0) {
            qsort(buffer, count, sizeof(int), compare);
            // 将排序后的块写入临时文件
            char chunkFilename[64];
            sprintf(chunkFilename, "chunk_%d.bin", chunkIndex);
            FILE* chunkFile = fopen(chunkFilename, "wb");
            if (chunkFile == NULL) {
                perror("Error opening chunk file");
                exit(EXIT_FAILURE);
            }

            fwrite(buffer, sizeof(int), count, chunkFile);
            fclose(chunkFile);

            chunkIndex++;
        }
    }

    fclose(inputFile);
    free(buffer);
    *numChunks = chunkIndex;
}

void initLoserTree(Node loserTree[], int k) {
    for (int i = 0; i < k; ++i) {
        loserTree[i].fromRun = -1;
        loserTree[i].value = INT_MAX;
    }
}

void adjustLoserTree(Node loserTree[], Node newNode, int k) {
    int i = (newNode.fromRun + k) / 2;
    while (i > 0) {
        if (newNode.value > loserTree[i].value || (newNode.value == loserTree[i].value && newNode.fromRun > loserTree[i].fromRun)) {
            Node temp = newNode;
            newNode = loserTree[i];
            loserTree[i] = temp;
        }
        i /= 2;
    }
    loserTree[0] = newNode;
}

void rebuildLoserTree(Node loserTree[], Node array[], int k) {
    for (int i = 0; i < k; ++i) {
        loserTree[i + k] = array[i];
    }
    for (int i = k - 1; i > 0; --i) {
        if (loserTree[i * 2].value < loserTree[i * 2 + 1].value) {
            loserTree[i] = loserTree[i * 2 + 1];
        } else {
            loserTree[i] = loserTree[i * 2];
        }
    }
    loserTree[0] = loserTree[1];
}

void kWayMergeWithLoserTree(const char* outputFilename, int numChunks) {
    FILE** chunkFiles = (FILE**)malloc(numChunks * sizeof(FILE*));
    for (int i = 0; i < numChunks; ++i) {
        char chunkFilename[64];
        sprintf(chunkFilename, "chunk_%d.bin", i);
        chunkFiles[i] = fopen(chunkFilename, "rb");
        if (chunkFiles[i] == NULL) {
            perror("Error opening chunk file");
            exit(EXIT_FAILURE);
        }
    }

    Node* loserTree = (Node*)malloc((2 * K) * sizeof(Node));
    Node* buffer = (Node*)malloc(numChunks * sizeof(Node));

    for (int i = 0; i < numChunks; ++i) {
        if (fread(&buffer[i].value, sizeof(int), 1, chunkFiles[i]) == 1) {
            buffer[i].fromRun = i;
        } else {
            buffer[i].fromRun = -1;
            buffer[i].value = INT_MAX;
        }
    }

    rebuildLoserTree(loserTree, buffer, numChunks);

    FILE* outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    while (loserTree[0].value != INT_MAX) {
        fprintf(outputFile, "%d\n", loserTree[0].value);

        int fromRun = loserTree[0].fromRun;
        if (fread(&buffer[fromRun].value, sizeof(int), 1, chunkFiles[fromRun]) != 1) {
            buffer[fromRun].value = INT_MAX;
        }

        adjustLoserTree(loserTree, buffer[fromRun], numChunks);
    }

    fclose(outputFile);
    for (int i = 0; i < numChunks; ++i) {
        fclose(chunkFiles[i]);
    }

    free(chunkFiles);
    free(loserTree);
    free(buffer);
}

int main() {
    const char* inputFilename = "input.txt";
    const char* outputFilename = "sorted_output.txt";
    int numElements = 1000;  // 测试文件中的元素数量

    // 生成测试文件
    generateTestFile(inputFilename, numElements);

    // 初步排序并保存到临时文件
    int numChunks;
    initialSortAndSave(inputFilename, &numChunks);

    // 多路平衡归并
    kWayMergeWithLoserTree(outputFilename, numChunks);

    printf("排序完成，结果保存在 %s 中。\n", outputFilename);
    system("pause");
    return 0;
}