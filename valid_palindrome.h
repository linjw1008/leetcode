#include "common.h"
class Solution {
public:
    bool isSame(char a, char b)
    {
        if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a == b)
            return true;
        else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) && 
                 ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z')) &&
                 (abs(a - b) == 0 || abs(a - b) == abs('a' - 'A')))
            return true;
        return false;
    }
    
    bool isValid(char a)
    {
        if (a >= '0' && a <= '9')
            return true;
        else if (a >= 'a' && a <= 'z')
            return true;
        else if (a >= 'A' && a <= 'Z')
            return true;
        else
            return false;
    }
    
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            //跳过非法字符
            while (left < right && !isValid(s[left])) ++left;
            while (right > left && !isValid(s[right])) --right;
            //cout << left << " " << right << endl;
            if (left == right)
                continue;
            if (!isSame(s[left], s[right]))
                return false;
            ++left, --right;
        }
        
        return true;
    }
};