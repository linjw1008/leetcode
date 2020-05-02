#include "common.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //单调栈实现
        stack<int> s;
        s.push(-1);
        int ans = 0;
        
        for (int i = 0; i < heights.size(); ++i)
        {
            //调整单调栈
            while (s.size() > 1 && heights[i] < heights[s.top()])
                s.pop();
            s.push(i);
            stack<int> tmp = s;
            //遍历栈
            while (tmp.size() > 1)
            {
                int cur = tmp.top();
                tmp.pop();
                int last = tmp.top();
                ans = max(ans, (i - last) * heights[cur]);
            }
        }

        return ans;
    }
};