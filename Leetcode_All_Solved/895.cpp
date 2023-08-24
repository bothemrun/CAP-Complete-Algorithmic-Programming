//m0
//priority queue based on frequency and timestamp.

#include<unordered_map>
#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        if(a[0] != b[0]) return a[0] < b[0];//max heap for frequency
        return a[1] < b[1];//max heap for timestamp
    }
};

class FreqStack {
public:
    unordered_map<int,int> val2freq;

    priority_queue< vector<int>, vector<vector<int>>, cmp_class > heap;

    int timestamp = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        if(val2freq.count(val) == 0) val2freq[val] = 0;
        int freq = ++val2freq[val];

        heap.push( vector<int>({freq, timestamp++, val}) );
    }
    
    int pop() {
        auto v = heap.top();
        heap.pop();

        val2freq[ v[2] ]--;
        return v[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
