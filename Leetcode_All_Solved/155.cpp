class MinStack {
public:
    vector<int> stac;
    vector<int> prefix_min;
    MinStack() {
        
    }
    
    void push(int val) {
        stac.push_back(val);
        if(prefix_min.size() == 0) prefix_min.push_back(val);
        else prefix_min.push_back( min(val, prefix_min.back() ) );
    }
    
    void pop() {
        stac.pop_back();
        prefix_min.pop_back();
    }
    
    int top() {
        return stac.back();
    }
    
    int getMin() {
        return prefix_min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
