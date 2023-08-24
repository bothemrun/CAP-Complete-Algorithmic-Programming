//m1
//priority queue based on frequency and timestamp.
//use tuple for heap

#define T3 tuple<int, int, int>
#include<queue>
#include<unordered_map>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const T3& a, const T3& b){
        //max heap
        if(get<0>(a) != get<0>(b) ) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    }
};

class FreqStack {
public:
    unordered_map<int,int> val2freq;

    priority_queue<T3, vector<T3>, cmp_class> heap;

    int timestamp = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        //if not exist, init with 0
        int f = ++val2freq[val];
        heap.push( T3(f, timestamp++, val) );
    }
    
    int pop() {
        T3 x = heap.top();
        heap.pop();

        val2freq[ get<2>(x) ]--;
        return get<2>(x);
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
