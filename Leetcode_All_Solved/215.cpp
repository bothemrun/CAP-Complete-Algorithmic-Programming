#include<algorithm>
class Solution {
private:
    static bool cmp_ptr(const int& a, const int& b){
        return a > b;//min heap
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        //NOTE: O(nlogk), not O(nlogn)
        vector<int> min_heap_k;
        for(const int& x:nums){
            min_heap_k.push_back(x); push_heap(min_heap_k.begin(), min_heap_k.end(), cmp_ptr);
            if(min_heap_k.size() > k){
                pop_heap(min_heap_k.begin(), min_heap_k.end(), cmp_ptr); min_heap_k.pop_back();
            }
        }
        return min_heap_k.front();
    }
};
