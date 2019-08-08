//有效括号
//用栈

#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> map;
        map = { {')', '('},
                {']', '['},
                {'}', '{'} };
        
        int len = s.size();

        stack<char> tmp;

        for(int i = 0; i < len; i++)
        {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(tmp.empty())return false;
                if(tmp.top() == map[s[i]])tmp.pop();
                else return false;
            }
            else tmp.push(s[i]);            
        }

        if(tmp.empty()) return true;
        else return false;
    }
};