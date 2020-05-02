#include "common.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); ++i)
            map[t[i]]++;
        
        int left = 0, right = 0;
        queue<int> q;
        pair<int, int> index = {0, -1};
        int ans = INT_MAX;
        
        //储存所有可能的起点
        for (int i = 0; i < s.size(); ++i)
        {
            if (map.find(s[i]) != map.end())
            {
                q.push(i);
            }
        }
        right = q.front();
        
        while (!q.empty())
        {
            left = q.front();
            q.pop();
            
            //到达了末尾，逐渐缩小左边的范围
            if (right >= s.size())
            {
                //cout << left << "  " << right << endl;
                //判断left - right串是否满足要求
                bool flag = true;
                for (auto& m : map)
                {
                    if (m.second > 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    if (ans > s.size() - left)
                    {
                        index = {left, s.size() - 1};
                        ans = s.size() - left;
                    }
                    map[s[left]]++;                    
                }
            }
            
            //先找到一个匹配的串
            while (right < s.size())
            {
                //cout << left << " " <<right << endl;
                if (map.find(s[right]) != map.end())
                    map[s[right]]--;
                
                //判断left - right串是否满足要求
                bool flag = true;
                for (auto& m : map)
                {
                    if (m.second > 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    if (ans >= right - left + 1)
                    {
                        index = {left, right};
                        ans = right - left + 1;
                    }
                    map[s[left]]++;
                    if (map[s[left]] > 0) //right 向右挪
                        right++;
                    else  //right 停留在原地，需要+1，抵消开头的--
                        map[s[right]]++;
                    
                    break;
                }
                
                right++;
            }
        }
        
        
        
        return s.substr(index.first, index.second - index.first + 1);
    }
};