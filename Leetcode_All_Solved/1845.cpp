#include<algorithm>
class SeatManager {
private:
    vector<int> min_heap;
    static bool cmp_ptr(const int& a, const int& b){
        return a > b;//min heap
    }
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)unreserve(i);
    }
    
    int reserve() {
        int x = min_heap.front();
        pop_heap(min_heap.begin(), min_heap.end(), cmp_ptr);min_heap.pop_back();
        return x;
    }
    
    void unreserve(int seatNumber) {
        min_heap.push_back(seatNumber); push_heap(min_heap.begin(), min_heap.end(), cmp_ptr);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
