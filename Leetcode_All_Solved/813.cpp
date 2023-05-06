//m0
//recursion with memo
//similar to 1105 Filling Bookcase Shelves.

#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<double> prefix;
    int max_partition;
    vector<vector<double>> memo;
    double enum_last_partition(const vector<int>& nums, const int& i, const int& p){
        if(i<0) return 0;

        if(memo[i][p] != notyet) return memo[i][p];

        if(p == 1) return memo[i][p] = prefix[i] / (double)(i+1);

        double ma = (-1);
        for(int last=i;last>=0;last--){
            ma = max(
                ma,
                enum_last_partition(nums, last-1, p-1) +
                ( prefix[i] - ( (last-1>=0)? prefix[last-1]:0 ) ) / (double)(i - (last-1))
            );
        }
        return memo[i][p] = ma;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        max_partition = k;

        prefix.resize(n);
        prefix[0] = (double)nums[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + (double)nums[i];

        memo.resize(n, vector<double>(max_partition + 1, notyet) );//1-indexed for partition count
        double ans = (-1);
        for(int p=1;p<=k;p++)
            ans = max(
                ans,
                enum_last_partition(nums, n-1, p)
            );
        return ans;
    }
};
