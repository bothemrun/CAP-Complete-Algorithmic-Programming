//m0
//(a) didn't optimize the pre_min_sum/suf_max_sum sizes from 3*n to 1*n+1
//(b) 3 pass


//[A] prefix max & suffix min n elements
//1. by priority queue

//[B] why can't use tallest billboard: DP recover param from val?

//1. in tallest billboard, O(n*diff) = O(20*5000) = 1e5
//2. here 1e10.

//O(nlogn)
#include<functional>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = (int)nums.size() / 3;
        //only look at the middle n indices, where prefix & suffix have >= n elements
        vector<long long> pre_min_sum(3*n);
        vector<long long> suf_max_sum(3*n);

        function<bool(const int&, const int&)> cmp1 = [](const int& a, const int& b){
            return a<b;//max heap, sink down
        };
        function<bool(const int&, const int&)> cmp2 = [](const int& a, const int& b){
            return a>b;//min heap, sink down
        };
        priority_queue<int, vector<int>, decltype(cmp1)> maxheap(cmp1);
        priority_queue<int, vector<int>, decltype(cmp2)> minheap(cmp2);

        long long presum = 0;
        for(int i=0;i<n-1;i++){
            maxheap.push(nums[i]);
            presum += nums[i];
        }
        for(int i=n-1;i<2*n;i++){
            maxheap.push(nums[i]);
            presum += nums[i];
            if(maxheap.size() > n){
                presum -= maxheap.top();
                maxheap.pop();
            }

            pre_min_sum[i] = presum;
        }

        long long sufsum = 0;
        for(int i=0;i<n-1;i++){
            minheap.push(nums[ (3*n-1) - i ]);
            sufsum += nums[ (3*n-1) - i ];
        }
        for(int i=2*n;i>=n;i--){
            minheap.push(nums[i]);
            sufsum += nums[i];
            if(minheap.size() > n){
                sufsum -= minheap.top();
                minheap.pop();
            }

            suf_max_sum[i] = sufsum;
        }


        //3 pass
        long long ans = LLONG_MAX;
        for(int i=n-1;i+1<=2*n;i++){
            //[_, i] & [i+1, ]
            ans = min(
                ans,
                pre_min_sum[i] - suf_max_sum[i+1]
            );
        }
        return ans;
    }
};
