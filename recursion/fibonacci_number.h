#ifndef _FIBONACCI_NUMBER_H_
#define _FIBONACCI_NUMBER_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fib(int N) {
        unordered_map<int, int> record;
        return fib(N, record);
    }

    int fib(int N, unordered_map<int, int>& record)
    {
        if (record.count(N) > 0)
            return record[N];
            
        if (N == 0 || N == 1)
            return N;
            
        int tmp = fib(N - 1, record) + fib(N - 2, record);
        record.insert(unordered_map<int, int>::value_type(N, tmp));
                    
        return tmp;
    }
};

#endif