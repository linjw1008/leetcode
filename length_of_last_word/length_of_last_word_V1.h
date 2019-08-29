#ifndef _LENGTH_OF_LAST_WORD_V1_H_
#define _LENGTH_OF_LAST_WORD_V1_H_

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        
        int len = 0;
        int index = s.size() - 1;

        while (s[index] == ' ')
            index--;
        for (int i = index; i >= 0; i--)
        {
            if (s[i] == ' ')
                break;
            len++;
        }

        return len;
    }
};

#endif