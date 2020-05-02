#include "common.h"

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;

        //依次考察个、十、百位
        for (int k = 1; k <= n; k = k * 10)
        {
            //当前考察位的右边的数字
            int right = n % k;
            //当前考察位的左边的数字(包括当前位)
            int left = n / k;
            //当前考察位的数字
            int cur = left % 10;
            //当前考察位的左边的数字（不包括当前位）
            left = left / 10;

            if (cur == 0)
                count += left * k;
            else if (cur == 1)
                count += left * k + right + 1;
            else
                count += (left + 1) * k;
            
            if (left == 0)
                break;
        }

        return count;
    }
};

