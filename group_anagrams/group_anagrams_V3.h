#ifndef _GROUP_ANAGRAMS_V3_H_
#define _GROUP_ANAGRAMS_V3_H_

//字母异位词分组
//哈希表
//排序

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> hash_map;
        hash_map.reserve(strs.size());
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hash_map[tmp].push_back(strs[i]);
        }
        int len = hash_map.size();
        ret.reserve(len);
        for (auto item : hash_map)
        {
            ret.push_back(item.second);
        }
        return ret;
    }
};

#endif