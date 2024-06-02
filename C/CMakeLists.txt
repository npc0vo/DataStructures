cmake_minimum_required(VERSION 3.27)
project(C CXX)
set(CMAKE_C_STANDARD 11)



add_executable(5_17 educoderOJ/Classproblems/5_17.cpp)
add_executable(3_9 educoderOJ/Classproblems/3_9.cpp)
add_executable(5_2 educoderOJ/Classproblems/5_2.cpp)
add_executable(C1_1 educoderOJ/lab0/C1_1.cpp
        educoderOJ/lab0/linearList.h)
add_executable(3_10 educoderOJ/Classproblems/3_10.cpp
        LinkList/SingleLinkList.h
        Graph/ActivityOnEdge.h)

add_executable(C1_2 educoderOJ/lab0/C1_2.cpp
       educoderOJ/lab0/slink.h)
add_executable(C1_3 educoderOJ/lab0/C1_3.cpp
        educoderOJ/lab0/tree.h)
add_executable(C2_1 educoderOJ/Huffman_lab1/C2_1.cpp)
add_executable(HelloWorld HelloWorld.cpp)
add_executable(SingleLinkList LinkList/SingleLinkList.cpp
        LinkList/SingleLinkList.h)
add_executable(DoubleLinkedList LinkList/DoubleLinkedList.cpp
        LinkList/DoubleLinkedList.h)
add_executable(CircularLinkedList LinkList/CircularLinkedList.cpp
        LinkList/CircularLinkedList.h)
add_executable(stack Stack/LinkedStack.cpp Stack/LinkedStack.h
        Stack/ArrayStack.h)
add_executable(sequentialQueue queue/sequentialQueue.cpp
        queue/sequentialQueue.h)
add_executable(circularQueue queue/circularQueue.cpp
        queue/circularQueue.h)
add_executable(kmp String/kmp.cpp)

add_executable(vm vm.cpp
        vm.h)
add_executable(binaryTree Tree/binaryTree.cpp
        Tree/binaryTree.h)
add_executable(huffman1 educoderOJ/Huffman_lab1/1.cpp)
add_executable(huffman2 educoderOJ/Huffman_lab1/2.cpp)
add_executable(huffman3 educoderOJ/Huffman_lab1/3.cpp)
add_executable(dfs Tree/dfs_tree.cpp)
add_executable(huffmanTree Tree/huffmanTree.cpp)
add_executable(huffmanC2_2 educoderOJ/Huffman_lab1/C2_2.cpp)
add_executable(huffmanC2_3 educoderOJ/Huffman_lab1/C2_3.cpp)
add_executable(Graph1 educoderOJ/Graph_lab2/1.cpp)
add_executable(Graph2 educoderOJ/Graph_lab2/2.cpp)
add_executable(adjacencyMatrix Graph/adjacencyMatrix.cpp)
add_executable(AdjacencyList Graph/AdjacencyList.cpp)
add_executable(Chainforwardstar Graph/Chainforwardstar.cpp)
add_executable(graphDFS Graph/graphDFS.cpp)
add_executable(graphBFS Graph/graphBFS.cpp)
add_executable(Prim Graph/Prim.cpp)
add_executable(Kruskal Graph/Kruskal.cpp)
add_executable(Dijkstra Graph/Dijkstra.cpp)
add_executable(misson1 educoderOJ/Graph_lab2/misson1.cpp)
add_executable(misson2 educoderOJ/Graph_lab2/misson2.cpp)
add_executable(floyed Graph/floyed.h Graph/floyed.cpp)
add_executable(ActivityOnEdge Graph/ActivityOnEdge.cpp
        Graph/ActivityOnEdge.h)

add_executable(threadedBinaryTree  "Tree/threadedBinaryTree .h"
        "Tree/threadedBinaryTree .cpp")
add_executable(AVL Search/AVL.cpp)
add_executable(BTree Search/BTree.cpp)
add_executable(hashTable Search/hashTable.cpp)
add_executable(staticSearch Search/staticSearch.cpp)
add_executable(insertionSort Sort/easySort.cpp)
add_executable(shellSort Sort/shellSort.cpp)
add_executable(secondOptimal Search/secondOptimal.cpp)
add_executable(blockSearch Search/blockSearch.cpp)
add_executable(binarySearchTree Search/binarySearchTree.cpp)
add_executable(heapSort Sort/heapSort.cpp)
add_executable(quickSort Sort/quickSort.cpp)
add_executable(mergeSort Sort/mergeSort.cpp)
add_executable(twoWayInsertionSort Sort/twoWayInsertionSort.cpp)
add_executable(listInsertionSort Sort/listInsertionSort.cpp)