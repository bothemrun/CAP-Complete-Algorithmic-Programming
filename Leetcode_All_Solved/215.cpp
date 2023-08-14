#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp_lam = [](const int& a, const int& b){
            return a > b;//minheap
        };
        priority_queue<int, vector<int>, decltype(cmp_lam) > size_minheap(cmp_lam);

        auto push = [&size_minheap, k](const int& x){
            size_minheap.push(x);
            if(size_minheap.size() > k) size_minheap.pop();
        };

        for(const int& x: nums)
            push(x);
        
        //k<=n
        return size_minheap.top();
    }
};
