//
// Created by Npc on 2024/5/28.
//
#include "stdio.h"
#include "stdlib.h"
//顺序查找
//最坏的比较次数为n+1
//时间复杂度O(n),ASL=(n+1)/2
int sequenceSearch(int a[],int value,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==value)
        {
            return i;
        }
    }
    return -1;
}

//二分查找1
//最坏的比较次数为log2(n+1)
//时间复杂度O(log2n),
int binarySearch1(int a[],int value,int n)//n是顺序表元素的个数
{
    //a[]是已经经过排序的
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==value)
        {
            return mid;
        }
        if(a[mid]>value)
        {
            high=mid-1;
        }
        if(a[mid]<value)
        {
            low=mid+1;
        }
    }
    return -1;
}

//二分查找的递归版本
int binarySearch2(int a[],int value,int low,int high)
{
    int mid=low+(high-low)/2;
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return binarySearch2(a,value,low,mid-1);
    if(a[mid]<value)
        return binarySearch2(a,value,mid+1,high);
}

//插值查找，基于二分查找，将查找点的选择改成自适应选择
/*将查找的点改进为如下：
mid=low+(key-a[low])/(a[high]-a[low])*(high-low)，*/
int insertionSearch(int a[],int value,int low,int high)
{
    int mid=low+(value-a[low])/(a[high]-a[low])*(high-low);
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return insertionSearch(a,value,low,mid-1);
    if(a[mid]<value)
        return insertionSearch(a,value,mid+1,high);
}
/*注：对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好的多。
 * 反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择。*/

//斐波那契查找
#define Max_SIZE 20
#define MAX 100
//--------构造斐波那契数列
void Fibonacci(int *F)
{
    F[0]=0;
    F[1]=1;
    for(int i=2;i<Max_SIZE;++i)
    {
        F[i]=F[i-1]+F[i-2];
    }
}
//---------斐波那契查找算法
int fibonacciSearch(int *a,int n,int key)
{
    int F[Max_SIZE];
    Fibonacci(F);
    int u=0;
    while(n>F[u])  //计算n位于斐波那契数列的位置
    {
        u++;
    }

    for(int i=n-1;i<F[u]-1;++i) //用数组最后一个元素补全斐波那契
    {
        a[i+1]=a[i];
    }

    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+F[u-1]-1;  //mid不是中间值而是黄金分割点
        //处理拓展情况
        if(mid>n&&a[n]==key)//若mid>n则说明是拓展的数值，返回n
        {
            return n;
        }
        else if(mid>n)
        {
            return -2; //查找的数据不存在
        }

        //类折半操作
        if(key==a[mid])
        {
            return mid;
        }//找到了
        else if(key>a[mid])
        {
            low=mid+1;
            u-=2;
        }
        else if(key<a[mid])
        {
            high=mid-1;
            u-=1;
        }
    }
    return -2;
}

// 声明函数
int sequenceSearch(int a[], int value, int n);
int binarySearch1(int a[], int value, int n);
int binarySearch2(int a[], int value, int low, int high);
int insertionSearch(int a[], int value, int low, int high);
void Fibonacci(int *F);
int fibonacciSearch(int *a, int n, int key);

int main() {
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int n = sizeof(a) / sizeof(a[0]);
    int value = 7;

    // 顺序查找测试
    int seqIndex = sequenceSearch(a, value, n);
    printf("顺序查找: 查找值 %d 的索引为 %d\n", value, seqIndex);

    // 二分查找测试
    int binIndex1 = binarySearch1(a, value, n);
    printf("二分查找: 查找值 %d 的索引为 %d\n", value, binIndex1);

    int binIndex2 = binarySearch2(a, value, 0, n-1);
    printf("二分查找（递归版）: 查找值 %d 的索引为 %d\n", value, binIndex2);

    // 插值查找测试
    int insIndex = insertionSearch(a, value, 0, n-1);
    printf("插值查找: 查找值 %d 的索引为 %d\n", value, insIndex);

    // 斐波那契查找测试
    int fibIndex = fibonacciSearch(a, n, value);
    printf("斐波那契查找: 查找值 %d 的索引为 %d\n", value, fibIndex);

    system("pause");

    return 0;
}