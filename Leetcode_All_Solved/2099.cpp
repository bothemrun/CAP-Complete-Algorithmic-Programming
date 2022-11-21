#include<queue>
#include<algorithm>
struct val_i{
    int val;
    int i;
};
class cmp_class{
public:
    bool operator()(const struct val_i& v1, const struct val_i& v2){
        return v1.val > v2.val;//min heap
    }
};
bool cmp_fn(const struct val_i& v1, const struct val_i& v2){
    return v1.i < v2.i;//ascending
}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        //NOTE: O(nlogn) down to O(nlogk)
        priority_queue<struct val_i, vector<struct val_i>, cmp_class> min_heap;
        for(int i=0;i<nums.size();i++){
            struct val_i v = {nums[i], i};
            min_heap.push(v);
            
            if(min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<struct val_i> largest_k;
        while(min_heap.size() != 0){
            largest_k.push_back(min_heap.top());
            min_heap.pop();
        }
        
        sort(largest_k.begin(), largest_k.end(), cmp_fn);
        vector<int> sub;
        for(struct val_i& v: largest_k)
            sub.push_back(v.val);
        return sub;
    }
};
