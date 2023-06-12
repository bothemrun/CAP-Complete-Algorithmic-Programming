#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class HitCounter {
public:
    vector<int> hit_time;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hit_time.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int left = upper_bound(hit_time.begin(), hit_time.end(), timestamp - 300) - hit_time.begin();
        return hit_time.size() - left;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
