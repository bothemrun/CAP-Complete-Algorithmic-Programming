//m2
//vector of stack / frequency map to --> stack
//O(1), improved from O(logn) priority queue method.

#include<unordered_map>
#include<stack>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class FreqStack {
public:
    unordered_map<int,int> val2freq;

    vector< stack<int> > freq2stack;
    //can be omitted, but pop_back from vectors takes time for system memory management
    int max_freq = 0;


    FreqStack() {
        //dummy for 0 frequency
        freq2stack.push_back( stack<int>() );
    }
    
    void push(int val) {
        int f = ++val2freq[val];

        if(!( f < freq2stack.size() ))
            freq2stack.push_back( stack<int>() );
        
        if(freq2stack.at(f).size() == 0) max_freq = f;
        
        freq2stack[f].push(val);
    }
    
    int pop() {
        int val = freq2stack.at(max_freq).top();

        freq2stack.at(max_freq).pop();

        val2freq[val]--;

        if(freq2stack.at(max_freq).size() == 0) max_freq--;

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
