//m0
//NOTE: pair is faster than tuple
#include<algorithm>
#include<queue>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool cmp_fn(const tuple<int,int>& a, const tuple<int,int>& b){
    //NOTE: descending in nums2
    return get<1>(a) > get<1>(b);
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
        vector<tuple<int,int>> nums(n);
        for(int i=0;i<n;i++)
            nums[i] = tuple<int,int>( nums1[i], nums2[i] );
        
        //NOTE: descending in nums2
        sort(nums.begin(), nums.end(), cmp_fn);


        this->k = k;
        for(int i=0;i<k-1;i++)
            push( get<0>( nums[i] ) );
        //NOTE: the rightmost i is always the min, and is the existing ending
        long long max_score = (-1);
        for(int i=k-1;i<n;i++){
            //make the heap size from k-1 to k
            push( get<0>( nums[i] ) );

            max_score = max(max_score, heap_sum * get<1>( nums[i] ) );

            //make the heap size from k to k-1, assert(minheap.size() > 0)
            pop();
        }

        return max_score;
    }
};
