#include<stack>
#include<utility>
class StockSpanner {
public:
    stack<pair<int,int>> monosta;//(price, idx)
    int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(monosta.size() != 0 && monosta.top().first <= price) monosta.pop();

        int span;
        if(monosta.size() == 0)
            span = i - (0-1);
        else span = i - monosta.top().second;

        monosta.push( pair<int,int>(price, i) );
        i++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
