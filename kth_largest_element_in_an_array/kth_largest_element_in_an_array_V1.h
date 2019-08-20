#ifndef _KTH_LARGEST_ELEMENT_IN_AN_ARRAY_V1_H_
#define _KTH_LARGEST_ELEMENT_IN_AN_ARRAY_V1_H_

//数组中的第K个最大元素
//小顶堆
//C++标准库实现

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> heap;
        int heap_size = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            heap_size++;
            heap.push(nums[i]);
            if(heap_size > k)
                heap.pop();
        }

        return heap.top();
    }
};

#endif