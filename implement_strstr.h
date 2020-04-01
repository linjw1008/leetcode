#include "common.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int hLen = haystack.size();
        int nLen = needle.size();
        if (hLen < nLen) return -1;
        
        for (int i = 0; i < hLen - nLen + 1; ++i)
        {
            if (needle[0] == haystack[i])
            {
                int j;
                for (j = 0; j < nLen && i + j < hLen;++j)
                    if (haystack[i + j] != needle[j]) break;
                
                if (j == nLen) return i;
            }
        }
        
        return -1;
    }
};