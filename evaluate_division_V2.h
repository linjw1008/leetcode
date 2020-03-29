//除法求值
//用BFS

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> map;

    double getdist(string &a, string &b)
    {
        auto it1 = map.find(a);
        auto it2 = map.find(b);
        if (it1 == map.end() || it2 == map.end())
        {
            return -1.0;
        }

        if (a == b)
        {
            return 1.0;
        }        

        //BFS遍历
        queue<pair<string, double>> Q;
        Q.push({a, 1.0});
        unordered_map<string, int> vis;
        vis[a] = 1;

        double ret = -1.0;
        while (!Q.empty())
        {
            auto f = Q.front();
            Q.pop();

            vis[f.first] = 1;

            if (f.first == b)
            {
                ret = f.second;
                break;
            }
            
            for (auto &pr : map[f.first])
            {
                if (vis[pr.first] == 0)
                {
                    Q.push({pr.first, pr.second * f.second});
                }
            }
        }

        return ret;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int index = equations.size();

        while (index--)
        {
            map[equations[index][0]].push_back({equations[index][1], values[index]});
            map[equations[index][1]].push_back({equations[index][0], 1.0 / values[index]});
        }
        
        vector<double> ret;

        for (auto &v : queries)
        {
            ret.push_back(getdist(v[0], v[1]));
        }

        return ret;
    }
};