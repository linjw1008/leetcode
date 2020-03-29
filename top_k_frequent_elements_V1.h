//用哈希表实现

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> tmp;
        vector<int> ret;
        map<int, int> freq_map;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            if (!freq_map.count(nums[i]))
            {
                freq_map.insert(map<int, int>::value_type(nums[i], 1));
                tmp.push_back(nums[i]);
            }
            else
            {
                freq_map[nums[i]]++;
            }
        }

        vector<vector<int>> ordered_vec(tmp.size(), vector<int>(2));
        for (int i = 0; i < tmp.size(); i++)
        {
            ordered_vec[i][0] = tmp[i];
            ordered_vec[i][1] = freq_map[tmp[i]];
        }

        sort(ordered_vec.begin(), ordered_vec.end(), cmp);

        for (int i = 0; i < k; i++)
        {
            ret.push_back(ordered_vec[i][0]);
        }
        
        return ret;
    }
};