#include "common.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> record(14, 0);
        for (int i = 0; i < nums.size(); ++i)
            record[nums[i]]++;
        
        int count = 0;
        for (int i = 1; i <= 13; ++i)
        {
            if (record[i] != 0) count++;
            else if (record[i] == 0 && count != 0 && record[0] == 0)
                break;
            else if (record[i] == 0 && count != 0 && record[0] != 0)
            {
                count++;
                record[0]--;
            }
        }

        return count == 5 || (count == 3 && record[0] == 2) || (count == 4 && record[0] == 1);
    }
};