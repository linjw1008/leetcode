//字母异位词分组

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> ans;
        int index = 0;
        
        for (auto s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if (map.find(tmp) != map.end())
            {
                ans[map[tmp]].push_back(s);
            }
            else
            {
                ans.push_back({s});
                map[tmp] = index++;
            }
        }
        
        return ans;
    }
};