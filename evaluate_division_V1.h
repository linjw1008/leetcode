//除法求值
//用并查集求解

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:

    //并查集类
    class UnionSet
    {
    private:
        unordered_map<string, string> str; //储存父节点
        unordered_map<string, double> val; //储存权重

        bool exist(string a)
        {
            return str.find(a) != str.end();
        }

        //初始化
        void init(string x)
        {
            if (exist(x))
            {
                return;
            }
            str[x] = x;
            val[x] = 1;
        }

        //查找父节点并压缩路径
        string findFather(string x)
        {
            if (str[x] == x)
            {
                return x;
            }

            string father = findFather(str[x]);

            //压缩路径
            val[x] = val[x] * val[str[x]];
            str[x] = father;

            return father;
        }    

    public:
        //合并集合
        void mergeNode(string a, string b, double value)
        {
            init(a);
            init(b);

            string fatherOfA = findFather(a);
            string fatherOfB = findFather(b);

            str[fatherOfB] = fatherOfA;
            val[fatherOfB] = val[a] * value / val[b];
        }

        //计算
        double calc(string a, string b)
        {
            if (!exist(a) || !exist(b))
            {
                return -1;
            }

            string fatherOfA = findFather(a);
            string fatherOfB = findFather(b);

            if (fatherOfA != fatherOfB)
            {
                return -1;
            }            

            return val[b] / val[a];
        }
    
    };

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionSet unionSet;

        //初始化并合并集合
        for (int i = 0; i < equations.size(); i++)
        {
            unionSet.mergeNode(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(unionSet.calc(queries[i][0], queries[i][1]));
        }
        

        return ans;
    }
};