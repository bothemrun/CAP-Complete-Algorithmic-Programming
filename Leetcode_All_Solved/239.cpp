//each element are only pushed and popped once, O(nlogn)
//lazy update / lazy pop
#include<queue>
#include<utility>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;//max heap
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp_class> lazy_maxheap;

        for(int i=0;i<k-1;i++)
            lazy_maxheap.push(pair<int,int>(nums[i], i) );
        
        for(int right=k-1;right<n;right++){
            lazy_maxheap.push(pair<int,int>(nums[right], right));

            int left = right - k + 1;

            while(lazy_maxheap.top().second < left)
                lazy_maxheap.pop();
            
            assert(lazy_maxheap.size()>=k);
            ans.push_back(lazy_maxheap.top().first);
        }

        return ans;
    }
};
