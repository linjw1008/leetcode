#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesis(ans, "", 0, 0, n);
        return ans;
    }
    
    void generateParenthesis(vector<string>& ans, string cur, int left, int right, int max)
    {
        if (left == max && right == max)
        {
            ans.push_back(cur);
            return;
        }
        
        if (left < max)
        {
            generateParenthesis(ans, cur + "(", left + 1, right, max);
        }
        if (right < left)
        {
            generateParenthesis(ans, cur + ")", left, right + 1, max);            
        }
    }
};