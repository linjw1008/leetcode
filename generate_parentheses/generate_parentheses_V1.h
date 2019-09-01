#ifndef _GENERATE_PARENTHESES_V1_H_
#define _GENERATE_PARENTHESES_V1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string tmp;
        generateParenthesis(n, ret, tmp, 0, 0);
        return ret;
    }

    void generateParenthesis(int n, vector<string>& ret, string parenthesis, int leftNum, int rightNum)
    {
        if (leftNum == rightNum && leftNum == n)
        {
            ret.push_back(parenthesis);
            return;
        }
        if (rightNum > leftNum || rightNum > n || leftNum > n)
            return;
        generateParenthesis(n, ret, parenthesis + ')', leftNum, rightNum + 1);
        generateParenthesis(n, ret, parenthesis + '(', leftNum + 1, rightNum);
    }
};

#endif