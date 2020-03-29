//用小顶堆
//自定义仿函数

#include <queue>
#include <vector>

using namespace std;

struct large
{
    bool operator() (int x, int y)
    {
        return x > y;
    }
};
    

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        priority_queue<int, vector<int>, large> min_queue;
        
        for (auto& n : nums)
        {
            min_queue.push(n);
            if (min_queue.size() > k)
            {
                min_queue.pop();
            }
        }
        
        return min_queue.top();
        
    }
};


