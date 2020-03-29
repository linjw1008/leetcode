//两个数组的交集

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> ans;
        unordered_set<int>::iterator it;
        
        for (int i = 0; i < nums1.size(); ++i)
        {
            if (set.count(nums1[i]) == 0) set.insert(nums1[i]);
        }
        
        for (int i = 0; i < nums2.size() && !set.empty(); ++i)
        {
            if ((it = set.find(nums2[i])) != set.end())
            {
                ans.push_back(*it);
                set.erase(it);
            }
        }
        
        return ans;
    }
};