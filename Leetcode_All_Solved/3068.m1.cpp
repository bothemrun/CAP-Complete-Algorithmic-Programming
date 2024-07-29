//m1

//[A] xor property: xor is both multiplication & division.

//1. so operations on edges (a,b) & (b,c) only affects a & c.
//2. since it's connectd (tree), we can have a path connecting any 2 nodes --> operation on any 2 nodes.

//[B] diff := x^k - x

//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();

        long long sum = 0;

        //diff
        int nonneg_cnt = 0;
        int min_nonneg = INT_MAX;
        int min_neg = INT_MAX;//abs

        for(const int& x: nums){
            sum += x;
            const int diff = (x^k) - x;

            if(diff >= 0){
                sum += diff;
                nonneg_cnt++;

                min_nonneg = min(min_nonneg, diff);
            }else{
                min_neg = min(min_neg, -diff);
            }
        }

        if(nonneg_cnt%2==0) return sum;
        return max(sum - min_nonneg, sum + (-min_neg));
    }
};
