//用小根堆

#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> count;

        for (auto num : nums)
        {
            count[num]++;
        }

        multimap<int, int, greater<int>> freq;

        for (auto i : count)
        {
            freq.insert(make_pair(i.second, i.first));
        }

        for (auto it = freq.begin(); it != freq.end() && k; it++, k--)
        {
            ret.push_back(it->second);
        }
        
        return ret;
    }
};