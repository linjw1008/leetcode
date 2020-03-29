#include "common.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int len = a.size() > b.size() ? a.size() : b.size();
        int aLen = a.size(), bLen = b.size();
        int carry = 0;
        
        while (aLen++ < len)
            a = '0' + a;
        while (bLen++ < len)
            b = '0' + b;
        while (--len >= 0)
        {
            if (a[len] - '0' + b[len] - '0' + carry == 1)
            {
                carry = 0;
                a[len] = '1';
            }
            else if (a[len] - '0' + b[len] - '0' + carry == 0)
            {
                carry = 0;
                a[len] = '0';
            }
            else if (a[len] - '0' + b[len] - '0' + carry == 2)
            {
                carry = 1;
                a[len] = '0';
            }
        }
        
        if (carry == 1) a = '1' + a;
        
        return a;
    }
};