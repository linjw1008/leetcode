#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mapAB;
        unordered_map<int, int> mapCD;
        int len = A.size();
        int ans = 0;
        
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                mapAB[A[i] + B[j]]++;
                mapCD[C[i] + D[j]]++;
            }
        }
        
        for (auto ab : mapAB)
            ans += ab.second * mapCD[0 - ab.first];
        
        return ans;
    }
};