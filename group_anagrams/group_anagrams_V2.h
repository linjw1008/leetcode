#ifndef _GROUP_ANAGRAMS_V2_H_
#define _GROUP_ANAGRAMS_V2_H_

//字母异位词分组
//哈希表
//数组记录单词

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> map;
        int count = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            int tmp[26] = {0};
            string sb;
            for (int j = 0; j < strs[i].size(); j++)
                tmp[strs[i][j] - 'a']++;
            for (int j = 0; j < 26; j++)
            {
                sb.append("#");
                sb.append(to_string(tmp[j]));
            }
            auto index = map.find(sb);
            if (index != map.end())
                ret[map[sb]].push_back(strs[i]);
            else
            {
                ret.push_back({strs[i]});
                map.insert(pair<string, int>(sb, count++));
            }
        }
        
        return ret;
    }
};

#endif