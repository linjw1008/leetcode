//四数之和
//双指针法（类似三数之和）

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<vector<int>, bool> hist;
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        if(len < 4) return {};

        for(int i = 0; i < len - 3; i++)
        {
            for(int j = i + 1; j < len - 2; j++)
            {
                if(hist.count({nums[i], nums[j]}) > 0) continue;
                hist.insert(map<vector<int>, bool>::value_type({nums[i], nums[j]}, true));
                if(nums[i] + nums[j] >= target && target > 0) break;
                int lptr = j + 1;
                int rptr = len - 1;
                while (lptr < rptr)
                {
                    if(nums[i] + nums[j] + nums[lptr] + nums[rptr] == target)
                    {
                        ret.push_back({nums[i], nums[j], nums[lptr], nums[rptr]});
                        do
                        {
                            rptr--;
                        }while (nums[rptr] == nums[rptr + 1] && lptr < rptr);
                        do
                        {
                            lptr++;
                        }while (nums[lptr] == nums[lptr - 1] && lptr < rptr);
                    }
                    else if(nums[i] + nums[j] + nums[lptr] + nums[rptr] > target)
                    {
                        do
                        {
                           rptr--;
                        }while (nums[rptr] == nums[rptr + 1] && lptr < rptr);                    
                    }
                    else
                    {
                        do
                        {
                            lptr++;
                        }while (nums[lptr] == nums[lptr - 1] && lptr < rptr);
                    }                    
                }
            }
        }

        return ret;
    }
};