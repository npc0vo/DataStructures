//
// Created by Npc on 2024/5/28.
//
#include "stdio.h"
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
    return -1
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