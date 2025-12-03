#include <iostream>
#include <stack>
using namespace std;
#define MAX_VAL 100001

class StockSpanner {
    stack<pair<int, int>> history;
    int currentDay;
public:
    StockSpanner() {
        history.push({MAX_VAL, 0});
        currentDay = 1;
    }
    
    int next(int price) {
        int result;

        while (price >= history.top().first) {
            history.pop();
        }

        result = currentDay - history.top().second;
        history.push({price, currentDay++});

        return result; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main() {

}