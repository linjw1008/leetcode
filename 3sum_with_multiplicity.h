#include "common.h"

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        vector<long> record(101, 0);
        long mod = 1e9 + 7;
        long ans = 0;


        //记录每个A[i]出现的次数
        for (int i = 0; i < A.size(); ++i)
            record[A[i]]++;

        for (int i = 0; i <= 100; ++i)
        {
            if (record[i] == 0) continue;
            //只选择i
            if (record[i] >= 3 && 3 * i == target) ans += record[i] * (record[i] - 1) * (record[i] - 2) / (3 * 2 * 1) % mod;
            //选择两个i
            if (record[i] >= 2 && target - i * 2 <= 100 &&  target - i * 2 >= 0 && target - i * 2 != i) ans += record[target - i * 2] * (record[i] * (record[i] - 1) / 2) % mod;

            for (int j = i + 1; j <= 100; ++j)
            {
                //i，j都选择，再选择另一个
                if (record[j] == 0) continue;
                if (target - j - i <= 100 && target - j - i > j)
                    ans = ans + record[target - j - i] * record[i] * record[j] % mod;
            }
        }

        return ans % mod;
    }
};