#include <iostream>
#include <vector>
#include <string>
#include "course_schedule\course_schedule_V2.h"

using namespace std;

int main()
{
    Solution s;

    vector<vector<int>> pre = {{1, 0}};

    cout << s.canFinish(2, pre) << endl;

    system("pause");

    return 0;    
}

