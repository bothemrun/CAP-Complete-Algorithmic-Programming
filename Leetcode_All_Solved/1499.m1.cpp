//m1
//m0/m1: monotonic queue by deque/priority queue

//[A] fix & rearrange, decouple:
//1. fix j.
//2. decouple: yi+yj + xj - xi = (yi-xi) + (yj+xj)

//[B] decoupled: sliding window max
//1. since j is fixed, so the sliding window max of (yi-xi)
//2. window by xj - xi <= k, xj - k <= xi

//[C] monotonic queue by priority queue with lazy update:
//1. the order of (1) maintaining the window (2) find max (3) update the deque, is crucial

//O(nlogn) 
#define val(i) ( points[i][1] - points[i][0] )
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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n =points.size();
        int ans = INT_MIN;

        function<bool(const tii&, const tii&)> cmp = [](const tii& a, const tii& b){
            return get<0>(a) < get<0>(b);//max heap, sink down
        };
        priority_queue<tii, vector<tii>, decltype(cmp)> maxheap(cmp);

        for(int j=0;j<n;j++){
            //the order is crucial

            //(1) maintain the window
            while(maxheap.size() && !( points[ get<1>( maxheap.top() ) ][0] >= points[j][0] - k ) ){
                maxheap.pop();
            }

            if(maxheap.size()){
                ans = max(
                    ans,
                    get<0>( maxheap.top() ) +
                    points[j][0] + points[j][1]
                );
            }

            //update
            while(maxheap.size() && !( get<0>( maxheap.top() ) > val(j) ) ){
                maxheap.pop();
            }
            maxheap.push(tii( val(j), j ));
        }

        return ans;
    }
};
