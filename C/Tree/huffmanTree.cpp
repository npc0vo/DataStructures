//
// Created by Npc on 2024/4/22.
//

#include "huffmanTree.h"


/*测试HuffmanTree的函数*/
int main()
{
    int weights[] = {5, 9, 12, 13, 16, 45}; // 样例权重
    int n = sizeof(weights) / sizeof(weights[0]); // 结点个数

    HuffmanTree HT; // HuffmanTree 数组
    CreateHuffmanTree(&HT, weights, n); // 构建 Huffman 树

    // 输出测试结果
    printf("Huffman Tree Constructed:\n");
    printf("Weight | Parent | Left | Right\n");
    for (int i = 1; i <= 2 * n - 1; i++) {
        printf("%6d | %6d | %4d | %5d\n", HT[i].weight, HT[i].parent, HT[i].left, HT[i].right);
    }
    system("pause");
/*  char ch;
  while((ch=getchar())!=EOF)
  {
      printf("%c",ch);
  }
    char *string;
    string= (char*)malloc(sizeof(char)*1000 );
    scanf("%s",string);
    printf("EEE%s",string);
    system("pause");*/

}