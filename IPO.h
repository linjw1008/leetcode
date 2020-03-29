//IPO

#include <map>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        multimap<int, int> map;
        int len = Profits.size();
        for (int i = 0; i < len; i++)
        {
            map.insert(make_pair(Capital[i], Profits[i]));
        }
        
        priority_queue<int> prique;

        while (k--)
        {
            for (auto iter = map.begin(); iter != map.end(); iter++)
            {
                if (iter->first <= W)
                {
                    prique.push(iter->second);
                    map.erase(iter);
                }
            }
            
            if (prique.empty())
            {
                break;
            }
            W += prique.top();
            prique.pop();
        }

        return W;
    }
};