#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class MovingAverage {
public:
    queue<int> q;
    int size;
    long long sum = 0;
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;

        if(q.size() > size){
            sum -= q.front();
            q.pop();
        }

        return (double)sum / (double)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
