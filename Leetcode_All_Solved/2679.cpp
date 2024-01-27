//m0
//vector of priority queues
//O(m * nlogn)
#include<algorithm>
#include<limits.h>
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
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums.front().size();

        auto cmp = [](const int& a, const int& b){
            return a<b;//max heap, sink down
        };
        //vector< priority_queue<int, vector<int>, decltype(cmp)> > maxheap(m, cmp);
        vector< priority_queue<int, vector<int>, decltype(cmp)> > maxheap(m, priority_queue<int, vector<int>, decltype(cmp)>(cmp) );

        for(int i=0;i<m;i++){
            for(const int& x: nums[i])
                maxheap[i].push(x);
        }

        int ans = 0;
        for(int j=0;j<n;j++){
            int ma = INT_MIN;

            for(int i=0;i<m;i++){
                ma = max(ma, maxheap[i].top());
                maxheap[i].pop();
            }

            ans += ma;
        }

        return ans;
    }
};
