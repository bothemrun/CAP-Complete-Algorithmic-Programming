//m0

//[A] division to multiplication --> histograms with rectangle area >= k

//[B] largest rectangle problems:
//1. 84. Largest Rectangle in Histogram hard
//2. 85. Maximal Rectangle hard

//[C] grow upwards, then leftwards & rightwards. --> last/next smaller

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline void monotonic_stack(const vector<int>& heights, vector<int>& bound, const int begin, const int end, const int delta){
        vector<int> monosta;

        for(int i=begin;i*delta <= end*delta;i += delta){
            while(monosta.size() && !( heights[ monosta.back() ] < heights[i] )){
                monosta.pop_back();
            }

            bound[i] = (monosta.size())? monosta.back():( begin - delta );

            monosta.push_back(i);
        }
    }

    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();

        vector<int> left(n), right(n);
        monotonic_stack(nums, left, 0, n-1, 1);
        monotonic_stack(nums, right, n-1, 0, -1);

        for(int i=0;i<n;i++){
            if( (long long)( (right[i]-1) - left[i] ) * (long long)nums[i] > threshold ){
                return (right[i]-1) - left[i];
            }
        }
        return (-1);
    }
};
