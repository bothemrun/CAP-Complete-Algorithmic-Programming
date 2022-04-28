#include<stack>
class CustomStack {
private:
    stack<int> sta;
    int max_size;
    vector<int> lazy_inc;
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
        lazy_inc = vector<int>(max_size, 0);
    }
    
    void push(int x) {
        if(sta.size() >= max_size)return;
        sta.push(x);
    }
    
    int pop() {
        if(sta.size() == 0)return (-1);
        int inc = lazy_inc[sta.size()-1];
        lazy_inc[sta.size()-1] = 0;
        if(sta.size() >= 2)lazy_inc[sta.size()-1-1] += inc;
        
        int val = sta.top();
        sta.pop();
        return val + inc;
    }
    
    void increment(int k, int val) {
        if(k > sta.size()) k = sta.size();
        if(sta.size() != 0) lazy_inc[k-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
