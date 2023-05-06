//m1
//bottom up dp
//similar to 1105 Filling Bookcase Shelves.
#include<algorithm>
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<double> prefix(n);
        prefix[0] = (double)nums[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];

        vector<vector<double>> memo(n, vector<double>(k+1));//1-indexed for partition count
        for(int i=0;i<n;i++){
            memo[i][1] = prefix[i] / (double)(i+1);

            for(int p=2;p<=k;p++){
                double ma = (-1);
                for(int last=i;last>=0;last--){
                    ma = max(
                        ma,
                        ( 
                        (last-1>=0)?
                        (memo[last-1][p-1] + (prefix[i] - prefix[last-1]) / (double)(i - (last-1)) ):0 
                        )
                    );
                }
                memo[i][p] = ma;
            }
        }

        return *max_element(memo[n-1].begin()+1, memo[n-1].end());
    }
};
