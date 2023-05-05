//m0
//recursion with memo
//NOTE: for i==0, we can set both of its skipped or non-skipeed sum to be arr[0]
#define notyet INT_MIN
#include<algorithm>
#include<limits.h>
class Solution {
public:
    vector<vector<int>> memo;
    int max_subarray(const vector<int>& arr, const int& i, bool skip){
        //NOTE: for i==0, just set both sum(skip or not) to be 0
        if(i<0) return 0;

        if(memo[i][skip] != notyet) return memo[i][skip];

        if(skip==false)
            return memo[i][false] = max(
                arr[i],
                arr[i] + max_subarray(arr, i-1, false)
            );
        //NOTE: if not check i-2>=0, so [skip=1] also include the case of the element itself alone.
        return memo[i][true] = max(
            arr[i] + max_subarray(arr, i-2, false),
            arr[i] + max_subarray(arr, i-1, true)
        );
    }
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        memo.resize(n, vector<int>(2, notyet));

        int ans = INT_MIN;
        for(int i=0;i<n;i++)
            ans = max({
                ans,
                max_subarray(arr, i, 0),
                max_subarray(arr, i, 1)
            });
        return ans;
    }
};
