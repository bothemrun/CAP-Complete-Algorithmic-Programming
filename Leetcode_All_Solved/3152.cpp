//O(Q*logN)
#define par(x) (x%2)
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;

        int start=0;
        while(start<n){
            int end = start;
            while(end+1<n && par(nums[end]) != par(nums[end+1]) ){
                end++;
            }

            if(start != end){
                left.push_back(start);
                right.push_back(end);
            }

            //update
            start = end+1;
        }

        int qn = queries.size();
        vector<bool> ans(qn);
        for(int q=0;q<qn;q++){
            int from = queries[q][0];
            int to = queries[q][1];

            if(from==to){
                ans[q] = true;
                continue;
            }

            int to_idx = lower_bound(
                right.begin(),
                right.end(),
                to
            ) - right.begin();

            int from_idx = upper_bound(
                left.begin(),
                left.end(),
                from
            ) - left.begin();
            from_idx--;

            ans[q] = to_idx == from_idx;
        }

        return ans;
    }
};
