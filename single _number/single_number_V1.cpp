//只出现一次的数字
//用哈希集，遍历数组

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> hash_set;

        for (int i = 0; i < len; i++)
        {
            if(hash_set.count(nums[i]))hash_set.erase(nums[i]);
            else hash_set.insert(nums[i]);
        }

        return *hash_set.begin();
    }
};