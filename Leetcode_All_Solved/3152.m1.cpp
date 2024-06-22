//m1
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

        //vector<int> cut(n, 0);
        int cut[max_n] = {0};
        int start=0;
        while(start<n){
            int end = start;
            while(end+1<n && par(nums[end]) != par(nums[end+1]) ){
                end++;
            }

            //also for length 1, start==end
            cut[end] = 1;

            //update
            start = end+1;
        }

        //vector<int> prefix(n);
        int prefix[max_n];
        //prefix.front() = cut.front();
        prefix[0] = cut[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + cut[i];

        int qn = queries.size();
        vector<bool> ans(qn);
        for(int q=0;q<qn;q++){
            int from = queries[q][0];
            int to = queries[q][1];

            ans[q] = range_sum(from, to-1) == 0;
        }
        return ans;
    }
};
