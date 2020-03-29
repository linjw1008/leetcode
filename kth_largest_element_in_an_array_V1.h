#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        multiset<int, greater<int>> uset;
        
        for (auto& n : nums)
        {
            uset.insert(n);
        }
        
        auto it = uset.begin();
        
        while (--k)
        {
            it++;
        }
        
        return *it;
    }
};