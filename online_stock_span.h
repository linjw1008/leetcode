//股票价格的跨度
//采用单调栈实现

#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    stack<vector<int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int scale = 1;
        while (!s.empty() && *s.top().begin() <= price)
        {
            scale += s.top()[1];
            s.pop();
        }
        
        s.push({price, scale});

        return scale;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */