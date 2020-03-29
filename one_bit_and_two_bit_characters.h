#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();

        int i = 0;
        while (i < len - 1)
        {
            if (bits[i] == 1)
            {
                i = i + 2;
            }
            else
            {
                i++;
            }
        }

        return i == len - 1;
    }
};