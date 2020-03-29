#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int maxLeft = 0;
        int maxRight = 0;
        
        for (int i = 0; i < 2 * len - 1; i++)
        {
            int left = i/2;
            int right = i/2 + i%2;

            while (left >= 0 && right < len && s[left] == s[right])
            {
                left--;
                right++;    
            }
            
            left++;right--;
            
            if (right - left > maxRight - maxLeft)
            {
                maxLeft = left;
                maxRight = right;
            }
        }
        
        return s.substr(maxLeft, maxRight - maxLeft + 1);
    }
};