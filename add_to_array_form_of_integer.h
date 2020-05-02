#include "common.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        int cary = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            int sum = A[A.size() - 1 - i] + K % 10 + cary;
            cary = sum / 10;
            ans.push_back(sum % 10);
            K = K / 10;
        }
        while (K)
        {
            int sum = K % 10 + cary;
            cary = sum / 10;
            ans.push_back(sum % 10);
            K = K / 10;
        }

        if (cary)
            ans.push_back(cary);

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};