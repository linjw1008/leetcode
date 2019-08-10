#include <iostream>
#include <vector>
#include "maximum_subarray/maximum_subarray_V1.h"

using namespace std;

int main()
{
    Solution s;

    vector<int> test_data = {-2, -1};

    cout << s.maxSubArray(test_data) << endl;

    system("pause");

    return 0;    
}

