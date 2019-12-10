#ifndef _TASK_SCHEDULER_V1_
#define _TASK_SCHEDULER_V1_

//任务调度器
//排序法

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        int time = 0;

        int map[26] = {0};
        for (int i = 0; i < len; i++)
        {
            map[tasks[i] - 'A']++;    
        }
        sort(map, map + 26);

        while (map[25] != 0)
        {
            for (int i = 0; i <= n; i++)
            {
                if (map[25] == 0)
                {
                    break;
                }
                if (i < 26 && map[25 - i] > 0)
                {
                    map[25 - i]--;
                }

                time++;
            }
            
            sort(map, map + 26);                       
        }
                
        return time;
    }
};

#endif