//m1
//monotonic queue-like method, but implemented by a priority queue with lazy update / lazy pop.

//each element are only pushed and popped once, O(nlogn)
//lazy update / lazy pop
#define tii tuple<int,int>
#include<functional>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        function<bool(const tii&, const tii&)> cmp = [](const tii& a, const tii& b){
            return get<0>(a) < get<0>(b);//max heap, sink down
        };
        priority_queue<tii, vector<tii>, decltype(cmp)> monoq(cmp);

        for(int i=0;i<k-1;i++){
            monoq.push(tii( nums[i], i ));
        }

        for(int i=k-1;i<n;i++){
            //update, add
            monoq.push(tii( nums[i], i ));

            //update, drop by indices, maintain the window
            while( get<1>( monoq.top() ) <= i-k ){
                monoq.pop();
            }

            //since monoq.push(i...), monoq.size() > 0
            ans.push_back( get<0>( monoq.top() ) );
        }
        return ans;
    }
};
