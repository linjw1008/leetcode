#include "common.h"

class Solution {
public:
    bool isMatchCore(string& s, string& p, int sPtr, int pPtr, unordered_map<string, bool>& mem)
    {
        string pos = to_string(sPtr) + ',' + to_string(pPtr);
        
        if (mem.find(pos) != mem.end())
            return mem[pos];
        
        //cout << sPtr << " " << pPtr << endl;
        if (pPtr == p.size() - 1 && p[pPtr] == '*')
            return mem[pos] = true;
        if (sPtr == s.size() && pPtr == p.size())
            return mem[pos] = true;
        else if ((sPtr == s.size() && pPtr != p.size()) || (sPtr != s.size() && pPtr == p.size()))
            return mem[pos] = false;
        
        if ((sPtr < s.size() && pPtr < p.size() && s[sPtr] == p[pPtr]) || (pPtr < p.size() && p[pPtr] == '?'))
            return mem[pos] = isMatchCore(s, p, sPtr + 1, pPtr + 1, mem);
        else if (pPtr < p.size() && p[pPtr] == '*')
            return mem[pos] = isMatchCore(s, p, sPtr + 1, pPtr, mem) || isMatchCore(s, p, sPtr, pPtr + 1, mem);
        
        return mem[pos] = false;
    }
    
    bool isMatch(string s, string p) {
        string p1;
        int index = 0, i = 0;
        while (i < p.size())
        {
            if (p[i] == '*')
            {
                p1.push_back(p[i]);
                //跳过剩余的*
                while (i < p.size() && p[i] == '*')
                    i++;
            }
            else
            {
                p1.push_back(p[i]);
                i++;
            }
        }
        //cout << p1 << " " << p << endl;
        unordered_map<string, bool> mem;
        
        return isMatchCore(s, p1, 0, 0, mem);
    }
};