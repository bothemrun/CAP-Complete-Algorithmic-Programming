//m2
//O(n^2) dp: wisdompeak Dual Sequence on 1
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<int>> memo;
    int lcs_dual_sequence_on1(const vector<int>& nums, const int i, const int j){
        if(!(j<n)) return 0;
        assert(i<j);

        if(memo[i][j] != notyet) return memo[i][j];

        return memo[i][j] = (nums[i]==nums[j])? (1 + lcs_dual_sequence_on1(nums, i+1, j+1) ):0;
    }

    int beautifulSplits(vector<int>& nums) {
        this->n = nums.size();
        memo.resize(n, vector<int>(n, notyet));

        int ans = 0;
        for(int i=0;i<n;i++){
            //nums1 [0, i]
            //nums2 [i+1, j], nums3[j+1, n-1]
            for(int j=i+1;j+1<n;j++){
                int end2 = (i+1) + i;
                //edge case
                //wrong: if(end2<n)
                if(end2 <= j){
                    if(lcs_dual_sequence_on1(nums, 0, i+1) >= i - (0-1) ){
                        ans++;
                        continue;
                    }
                }
                int end3 = (j+1) + j - (i+1);
                if(end3 < n){
                    if(lcs_dual_sequence_on1(nums, i+1, j+1) >= j - i){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
