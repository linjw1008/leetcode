#include "common.h"
/*
小顶堆
*/
//上浮节点
//调整最后一个叶子节点
void up_small_heap(vector<int>& arr)
{
    int childIndex = arr.size() - 1;
    int parentIndex = (childIndex - 1) / 2;

    while (parentIndex >= 0 && arr[childIndex] < arr[parentIndex])
    {
        swap(arr[childIndex], arr[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

//下沉节点
//把特定的父节点下沉
void down_small_heap(vector<int>& arr, int parentIndex, int length)
{
    int childIndex = 2 * parentIndex + 1;
    while (childIndex < length)
    {
        //定位到最小的孩子
        if (childIndex + 1 < length && arr[childIndex + 1] < arr[childIndex])
            childIndex++;
        //父节点比两个孩子都小，无需进行调整
        if (arr[parentIndex] <= arr[childIndex])
            break;
        swap(arr[parentIndex], arr[childIndex]);

        parentIndex = childIndex;
        childIndex = 2 * parentIndex + 1;
    }
}

//建立堆，把所有父节点依次下沉
void build_small_heap(vector<int>& arr)
{
    int length = arr.size();
//    int parentIndex = (length - 1) / 2;
    int parentIndex = (length - 2) / 2;  //应该-2？？？
      
    while (parentIndex >= 0)
    {
        down_small_heap(arr, parentIndex, length);
        parentIndex--;
    }

}

//获取第一个元素
int top_small_heap(vector<int>& arr)
{
    return arr[0];
}

//删除第一个元素
void pop_small_heap(vector<int>& arr)
{
    arr[0] = arr[arr.size() - 1];
    arr.erase(arr.end() - 1);
    down_small_heap(arr, 0, arr.size());
}

//插入元素
void push_small_heap(vector<int> &arr, int val)
{
    arr.push_back(val);
    up_small_heap(arr);
}

/*
大顶堆
*/
//上浮节点
void up_large_heap(vector<int>& arr)
{
    int childIndex = arr.size() - 1;
    int parentIndex = (childIndex - 1) / 2;

    while (parentIndex >= 0)
    {
        if (arr[parentIndex] >= arr[childIndex])
            break;
        swap(arr[parentIndex], arr[childIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

//下沉节点
void down_large_heap(vector<int>& arr, int parentIndex, int length)
{
    int childIndex = 2 * parentIndex + 1;
    while (childIndex < length)
    {
        //找出最大的孩子节点
        if (childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex])
            childIndex++;
        if (arr[childIndex] <= arr[parentIndex])
            break;
        swap(arr[parentIndex], arr[childIndex]);
        parentIndex = childIndex;
        childIndex = 2 * parentIndex + 1;
    }
}

//建立大顶堆
void build_large_heap(vector<int>& arr)
{
    int length = arr.size();
    int parentIndex = (length - 1) / 2;
    while (parentIndex >= 0)
    {
        down_large_heap(arr, parentIndex, length);
        parentIndex--;
    }
}

int top_large_heap(vector<int>& arr)
{
    return arr[0];
}

void pop_large_heap(vector<int>& arr)
{
    arr[0] = arr[arr.size() - 1];
    arr.erase(arr.end() - 1);
    down_large_heap(arr, 0, arr.size());
}

void push_large_heap(vector<int>& arr, int val)
{
    arr.push_back(val);
    up_large_heap(arr);
}

int main()
{
    vector<int> array = {1, 3, 2, 6, 5, 7, 8, 9, 10, 0, 11};
    build_small_heap(array);
    int len = array.size();
    for (int i = 0; i < len; ++i)
    {
        cout << top_small_heap(array) << " ";
        pop_small_heap(array);
    }
    cout << endl;

    vector<int> array1 = {1, 3, 2, 6, 5, 7, 8, 9, 10, 0};
    build_large_heap(array1);
    len = array1.size();
    for (int i = 0; i < len; ++i)
    {
        cout << top_large_heap(array1) << " ";
        pop_large_heap(array1);
    }


}