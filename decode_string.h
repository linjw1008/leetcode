//字符串解码

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> nStack;
        stack<string> sStack;
        string cur = "";
        int num = 0;

        for (char c : s)
        {
            if (isdigit(c)) //找出连续的数字
            {
                num = num * 10 + (c - '0');
            }
            else if (isalpha(c)) //将连续字符组成字符串
            {
                cur.push_back(c);
            }
            else if (c == '[')  //将之前的字符串和数字分别入栈
            {
                sStack.push(cur);
                nStack.push(num);
                cur = "";
                num = 0;
            }
            else if (c == ']')
            {
                string tmp = cur;
                for (int i = 0; i < nStack.top() - 1; i++)
                {
                    cur += tmp;
                }
                cur = sStack.top() + cur;
                sStack.pop();
                nStack.pop();
            }
        }
        
        return cur;
    }
};