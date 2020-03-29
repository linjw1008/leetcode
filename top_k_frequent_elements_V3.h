//用大顶堆

#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, tmp> max_queue;
        map<int, int> num_to_count;
        vector<int> ret;
         
        //计数
        for (int i = 0; i < nums.size(); i++)
        {
            num_to_count[nums[i]]++;
        }
        
        //插入优先队列
        for (auto nc : num_to_count)
        {
            max_queue.push(nc);
        }
        
        for (int i = 0; i < k; i++)
        {
            ret.push_back(max_queue.top().first);
            max_queue.pop();
        }
            
        return ret;
    }
    
    
    struct tmp
    {
        bool operator() (pair<int, int> a, pair<int, int> b)
        {
            return a.second < b.second;
        }
    };
};