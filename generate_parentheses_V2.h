#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        dp.resize(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                vector<string> in = dp[j];
                vector<string> out = dp[i - j - 1];
                for (int k = 0; k < in.size(); k++)
                {
                    for (int h = 0; h < out.size(); h++)
                    {
                        dp[i].push_back("(" + in[k] + ")" + out[h]);
                    }
                }
            }
        }
        
        return dp[n];
    }

};