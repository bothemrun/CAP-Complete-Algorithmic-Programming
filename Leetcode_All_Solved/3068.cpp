//m0

//[A] xor property: xor is both multiplication & division.

//1. so operations on edges (a,b) & (b,c) only affects a & c.
//2. since it's connectd (tree), we can have a path connecting any 2 nodes --> operation on any 2 nodes.

//[B] sort x^k - x
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
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i] = ( nums[i]^k ) - nums[i];
        }
        sort(diff.begin(), diff.end(), greater<int>());

        long long diff_sum = 0;
        int j=0;
        for(;j+1<n;j += 2){
            if(diff[j]<0 || diff[j+1]<0) break;

            diff_sum += diff[j] + diff[j+1];
        }
        if(j+1<n && diff[j]>=0 && diff[j+1]<0){
            diff_sum = max(diff_sum, diff_sum + diff[j] + diff[j+1]);
        }

        long long ans = diff_sum;
        for(const int& x: nums) ans += x;
        return ans;
    }
};
