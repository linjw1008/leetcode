#include <string>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
        {
            return "0";
        }
        if (denominator == 0)
        {
            return "";
        }
        
        string ret;
        
        //转换成long long， 防止取绝对值时溢出
        long long num = (long long)numerator;
        long long den = (long long)denominator;
        
        //若分子分母符号不同，取正号
        if ((num > 0) ^ (den > 0))
        {
            ret.push_back('-');
        }
        
        //全转换成正数
        num = abs(num);
        den = abs(den);
        
        //整数部分
        ret.append(to_string(num/den));
        
        //小数部分
        num = num % den;
        if (num == 0)
        {
            return ret;
        }
        ret.push_back('.');
        
        int index = ret.size() - 1;
        
        unordered_map<int, int> record; //记录重复数的下标
        
        while (num && record.count(num) == 0) 
        {
            record[num] = ++index;
            num *= 10;
            ret += to_string(num/den);
            num = num % den;
        }
        if (record.count(num) == 1)
        {
            ret.insert(record[num], "(");
            ret.push_back(')');
        }
        
        return ret;
    }
};