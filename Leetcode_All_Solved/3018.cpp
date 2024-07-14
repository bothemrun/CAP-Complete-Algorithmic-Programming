//m0

//[A] simplified problem: not the operation

//1. ans(i, j) with [i, j] remained, related info?

/*
let q := ans(i, j),
if(nums[i] or nums[j] >= queries[q]):
    we can remove [i] or [j],
    and update ans(i+1, j) or ans(i, j-1)
*/

//2. the results don't come from combining many smaller segments, but 1 shrinking segment.

//3. --> shrink DP, interval II, 

//4. final ans = max ans(i, i) for i


//[B] with the operation:

//1. the power of dp is to skip/not choose elements --> subsequence

//O(n^2)

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<int>> memo;

    int anti_shrink(const vector<int>& nums, const vector<int>& queries, int i, int j){
        if(i==0 && j==n-1) return 0;
        //TODO

        if(memo[i][j] != notyet) return memo[i][j];

        int ret = 0;
        if(i-1>=0){
            //choose or skip [i-1]
            ret = max(
                ret,
                anti_shrink(nums, queries, i-1, j)
            );

            int q = anti_shrink(nums, queries, i-1, j);
            if(q < queries.size() && nums[i-1] >= queries[q]){
                ret = max(ret, 1 + q);
            }
        }

        if(j+1<n){
            //choose or skip [j+1]
            ret = max(
                ret,
                anti_shrink(nums, queries, i, j+1)
            );

            int q = anti_shrink(nums, queries, i, j+1);
            if(q < queries.size() && nums[j+1] >= queries[q]){
                ret = max(ret, 1 + q);
            }
        }

        return memo[i][j] = ret;
    }

    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        this->n = nums.size();

        memo.resize(n, vector<int>(n, notyet));
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int q = anti_shrink(nums, queries, i, i);
            if(q < queries.size() && nums[i] >= queries[q] ){
                q++;
            }

            ans = max(ans, q);
        }
        return ans;
    }
};
