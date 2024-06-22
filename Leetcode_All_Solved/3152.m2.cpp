//m2
//O(N + Q)
#define max_n ((int)1e5)
#define par(x) (x%2)

#define trim(i) ( (i>=0)? prefix[i]:0 )
#define range_sum(i, j) ( trim(j) - trim(i-1) )

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int cut[max_n];
        for(int i=0;i+1<n;i++){
            cut[i] = par(nums[i]) == par(nums[i+1]);
        }
        //no need to set cut.back()

        int prefix[max_n];
        prefix[0] = cut[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + cut[i];

        int qn = queries.size();
        vector<bool> ans(qn);
        for(int q=0;q<qn;q++){
            ans[q] = range_sum(
                queries[q][0],
                queries[q][1] - 1
            ) == 0;
        }
        return ans;
    }
};
