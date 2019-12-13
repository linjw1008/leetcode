#ifndef _LARGEST_NUMBER_V1_H_
#define _LARGEST_NUMBER_V1_H_

#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    static bool cmp(const string& s1, const string& s2)
    {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        string ret;
        vector<string> nums_string;
        nums_string.reserve(len);

        for (int i = 0; i < len; i++)
        {
            nums_string.push_back(to_string(nums[i]));
        }

        sort(nums_string.begin(), nums_string.end(), cmp);

        for (int i = 0; i < len; i++)
        {
            ret += nums_string[i];
        }

        if (ret[0] == '0' && len > 0)
        {
            return "0";
        }
        

        return ret;
    }
};

#endif
