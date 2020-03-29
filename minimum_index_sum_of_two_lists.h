//两个列表的最小索引总和
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minIndexSum = INT_MAX;
        unordered_map<string, int> map;
        vector<string> ans;
        vector<pair<int, int>> ansIndex;
        
        for (int i = 0; i < list1.size(); ++i)
        {
            map[list1[i]] = i;
        }
        
        //找出所有最小索引
        for (int i = 0; i < list2.size(); ++i)
        {
            if (map.find(list2[i]) != map.end() && map[list2[i]] + i <= minIndexSum)
            {
                if (map[list2[i]] + i < minIndexSum)
                {
                    ansIndex.clear();
                }
                minIndexSum = map[list2[i]] + i;
                ansIndex.push_back(pair<int, int>(map[list2[i]], i));
            }
        }
        
        for (int i = 0; i < ansIndex.size(); ++i)
        {
            ans.push_back(list1[ansIndex[i].first]);
        }
        
        return ans;
    }
};