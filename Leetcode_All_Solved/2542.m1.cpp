//m1
//NOTE: pair is faster than tuple, due to some compiler options.
#include<algorithm>
#include<queue>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    //NOTE: descending in nums2
    return a.second > b.second;
}

class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//sink down, min heap
    }
};

class Solution {
public:
    int k;
    priority_queue<int, vector<int>, cmp_class> minheap;
    long long heap_sum = 0;
    inline void pop(){
        heap_sum -= minheap.top();

        minheap.pop();
    }
    inline void push(const int& val){
        heap_sum += val;

        minheap.push(val);
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++)
            nums[i] = pair<int,int>(nums1[i], nums2[i] );
        
        //NOTE: descending in nums2
        sort(nums.begin(), nums.end(), cmp_fn);


        this->k = k;
        for(int i=0;i<k-1;i++)
            push( nums[i].first );
        long long max_score = (-1);
        //NOTE: the rightmost i is the min and the existing endpoint.
        for(int i=k-1;i<n;i++){
            //heap size from k-1 to k
            push( nums[i].first );

            max_score = max(max_score, heap_sum * nums[i].second );

            //heap size from k to k-1
            pop();
        }

        return max_score;
    }
};
