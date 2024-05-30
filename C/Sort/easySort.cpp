#include "iostream"
#include "cstdlib"
#include "ctime"

//几个最简单的排序方法
using namespace std;

//随机初始化数组
void setArray(int *data, int size)
{
    cout << "随机初始化" << size << "个数" << endl;
    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 100 + 1;
    }
}

//打印数组
void Print(int *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

//交换数组的两个元素
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//冒泡排序
void bubbleSort(int *data, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j + 1] < data[j])
            {
                Swap(data[j + 1], data[j]);
            }
        }
    }
}

//直接插入排序
void insertionSort(int *data, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = data[i]; //抽起来的元素
        int j = i - 1;
        //将data[i]插入到已排序的data[0...i-1]
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

//简单选择排序
void choiceSort(int *data,int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=data[i];
        for(int j=i+1;j<size;j++)
        {
            if(data[j]<min)
            {
                min=data[j];
            }
        }
        Swap(data[i],min);
    }
}
int main()
{
    srand((unsigned)time(NULL)); //设置随机数种子

    const int size = 10;
    int data[size];

    // 初始化数组
    setArray(data, size);

    // 打印原始数组
    cout << "原始数组: ";
    Print(data, size);

    // 使用冒泡排序
    bubbleSort(data, size);
    cout << "冒泡排序后的数组: ";
    Print(data, size);

    // 重新初始化数组
    setArray(data, size);

    // 打印重新初始化后的数组
    cout << "重新初始化后的数组: ";
    Print(data, size);

    // 使用插入排序
    insertionSort(data, size);
    cout << "插入排序后的数组: ";
    Print(data, size);


    //使用直接选择排序
    choiceSort(data,size);
    cout<<"直接选择排序后的数组:";
    Print(data,size);


    system("pause");
    return 0;
}
