//m0
//[A] fix & rearrange, decouple:
//1. fix j.
//2. decouple: yi+yj + xj - xi = (yi-xi) + (yj+xj)

//[B] decoupled: sliding window max
//1. since j is fixed, so the sliding window max of (yi-xi)
//2. window by xj - xi <= k, xj - k <= xi

//[C] monotonic queue by deque
//1. the order of (1) maintaining the window (2) find max (3) update the deque, is crucial

//O(n) 
#define val(i) ( points[i][1] - points[i][0] )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;

        deque<int> deck;//indices
        for(int j=0;j<n;j++){
            //the order is crucial

            //first maintain the window
            while(deck.size() && !( points[ deck.front() ][0] >= points[j][0] - k ) ){
                deck.pop_front();
            }

            if(deck.size()){
                ans = max(
                    ans,
                    val( deck.front() ) +
                    points[j][0] + points[j][1]
                );
            }

            //update deque
            while(deck.size() && !( val( deck.back() ) > val(j) ) ){
                deck.pop_back();
            }
            deck.push_back(j);
        }
        return ans;
    }
};
