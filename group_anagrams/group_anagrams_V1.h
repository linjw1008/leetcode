#ifndef _GROUP_ANAGRAMS_V1_H_
#define _GROUP_ANAGRAMS_V1_H_

//字母异位词分组
//哈希表
//超出时间限制

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<unordered_map<char, int>> map;
        for (int i = 0; i < strs.size(); i++)
        {
            int j = 0;
            //查询是否在哈希集中
            for (; j < map.size(); j++)
            {
                //处理空字符串
                if (map[j].size() == 0 && strs[i].size() == 0)
                {
                    ret[j].push_back(strs[i]);
                    break;
                }
                else if (map[j].size() <= strs[i].size())
                {
                    int k = 0;
                    //逐个字符查询
                    unordered_map<char, int> tmp = map[j];
                    for (; k < strs[i].size(); k++)
                    {
                        if(tmp.count(strs[i][k]) == 0)
                            break;
                        else if (tmp[strs[i][k]] == 0)
                            break;
                        if (--tmp[strs[i][k]] == 0)
                            tmp.erase(strs[i][k]);
                    }
                    //与哈希集的第j个元素匹配，插入结果并退出循环
                    if (k == strs[i].size() && tmp.size() == 0)
                    {
                        ret[j].push_back(strs[i]);
                        break;
                    }
                }
            }
            //不在哈希集中，则新添加入哈希集以及结果
            if (j == map.size())
            {
                ret.push_back({strs[i]});
                unordered_map<char, int> tmp;
                for (int h = 0; h < strs[i].size(); h++)
                {
                    if (tmp.count(strs[i][h]) > 0)
                        tmp[strs[i][h]]++;
                    else
                        tmp.insert(unordered_map<char, int>::value_type(strs[i][h], 1));                   
                }
                map.push_back(tmp);                
            }
        }
        
        return ret;
    }
};

#endif