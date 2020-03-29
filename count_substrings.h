//回文子串

#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = 0;

        for (int center = 0; center < 2 * len - 1; center++)
        {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < len && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }
        }
        
        return res;
    }
};