#ifndef _COURSE_SCHEDULE_V1_H_
#define _COURSE_SCHEDULE_V1_H_

//课程表
//拓扑排序、查找是否存在环
//用邻接表实现

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<list<int>> G(numCourses, list<int>({}));
        queue<int> que;

        //初始化入度数组和邻接表
        for(auto p : prerequisites)
        {
            degree[p[0]]++;
            G[p[1]].push_back(p[0]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(degree[i] == 0)
                que.push(i);
        }

        while(!que.empty())
        {
            int pre = que.front();
            que.pop();
            for(auto senior : G[pre])
            {
                degree[senior]--;
                if(degree[senior] == 0) 
                    que.push(senior);
            }
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(degree[i] != 0)
                return false;
        }

        return true;
    }
};


#endif