#include <iostream>
#include <vector>
#include <string>
#include "word_search/word_search_V1.h"

using namespace std;

int main()
{
    Solution s;

    vector<vector<char>> board =
                {{'A','B','C','E'},
                 {'S','F','C','S'},
                 {'A','D','E','E'}};

    string word = "ABCCED"; 

    cout << s.exist(board, word) << endl;

    system("pause");

    return 0;    
}

