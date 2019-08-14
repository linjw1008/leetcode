#include <iostream>
#include <vector>
#include <string>
#include "minimum_path_sum\minimum_path_sum_V2.h"

using namespace std;

int main()
{
    Solution s;

    vector<vector<int>> grid =
                {{'1','3','1'},
                 {'1','5','1'},
                 {'4','2','1'}};


    cout << s.minPathSum(grid) << endl;

    system("pause");

    return 0;    
}

