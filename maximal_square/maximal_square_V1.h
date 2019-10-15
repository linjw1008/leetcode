#ifndef _MAXIMAL_SQUARE_V1_H_
#define _MAXIMAL_SQUARE_V1_H_

//最大正方形
//动态规划

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int** dp;
    int x;
    int y;
    int max_length = 0;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       x = matrix.size(); 
       if(x != 0) y = matrix[0].size();
       dp = new int*[x];
       for(int i = 0; i < x; i++) dp[i] = new int[y];

       for(int i = 0; i < x; i++)
       {
           for(int j = 0; j < y; j++)
           {
               if(i == 0 || j == 0) dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
               else 
               {
                   dp[i][j] = matrix[i][j] == '0' ? 0 : (1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])));
               }
               max_length = max(max_length, dp[i][j]);
           }
       }

       return max_length*max_length;
    }
};

#endif