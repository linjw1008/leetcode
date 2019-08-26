#ifndef _REVERSE_STRING_H_
#define _REVERSE_STRING_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        reverse(s, 0);
    }

private:
    void reverse(vector<char>& s, int index)
    {
        if (index == s.size() - 1)
            return;
        
        reverse(s, index + 1);

        char tmp = s[index];
        for (int i = index + 1; i < s.size(); i++)
        {
            s[i - 1] = s[i];
            if (i == s.size() - 1)
                s[i] = tmp;
        }
    }
};

#endif