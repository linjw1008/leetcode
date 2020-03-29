//两个数组的交集 II
//排序+双指针法


#include <vector>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int left = 0;
        int right = 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while (left < nums1.size() && right < nums2.size())
        {
            if (nums1[left] == nums2[right])
            {
                ans.push_back(nums1[left]);
                left++; right++;
            }
            else if (nums1[left] < nums2[right]) left++;
            else right++;
        }
        
        return ans;
    }
};