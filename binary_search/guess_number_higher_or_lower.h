#include "common.h"

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) break;
            else if (res < 0) right = mid - 1;
            else left = mid + 1;
        }
        
        return mid;
    }
};