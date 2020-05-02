#include "common.h"

class Solution {
public:
    int mod = 1e9 + 7;

    int fib(int n, unordered_map<int, int>& mem)
    {
        if (n <= 1) return n;
        if (mem.find(n) != mem.end()) return mem[n];
        else return mem[n] = (fib(n - 1, mem)%mod + fib(n - 2, mem)%mod) % mod;
    }

    int fib(int n) {
        unordered_map<int, int> mem;
        return fib(n, mem);
    }
};