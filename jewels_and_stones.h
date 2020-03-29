#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> set;
        int ans = 0;
        
        for (auto j : J) set.insert(j);
        for (auto s : S) if (set.find(s) != set.end()) ans++;
        
        return ans;
    }
};