//电话号码数字组合
//暴力法

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> number2letter;
        number2letter['2'] = "abc";
        number2letter['3'] = "def";
        number2letter['4'] = "ghi";
        number2letter['5'] = "jkl";
        number2letter['6'] = "mno";
        number2letter['7'] = "pqrs";
        number2letter['8'] = "tuv";
        number2letter['9'] = "wxyz";

        short len = digits.size();

        vector<string> ret;

        for(int i = 0; i < len; i++)// 遍历输入
        {
            vector<string> ret_tmp;

            for(int j = 0; j < ret.size(); j++)//遍历当前已有的队列
            {
                for(int k = 0; k < number2letter[digits[i]].size(); k++)//遍历当前输入的数字对应的字母
                    ret_tmp.push_back(ret[j] + number2letter[digits[i]][k]);
            }
            
            swap(ret, ret_tmp);
            
            if(ret.size() == 0)
            {
                for(int h = 0; h < number2letter[digits[i]].size(); h++)
                {
                    char tmp = number2letter[digits[i]][h];
                    string tmp2;
                    tmp2 += tmp;
                    ret.push_back(tmp2);
                }
            }

        }

        return ret;
    }
};