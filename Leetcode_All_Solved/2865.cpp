//m0
//O(n^2) greedy enumeration
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();

        long long max_sum = 0;

        for(int i=0;i<n;i++){
            vector<int> heights(n);

            heights[i] = maxHeights[i];

            long long sum = 0;
            sum += heights[i];

            for(int j=(i-1);j>=0;j--){
                heights[j] = min( heights[j+1], maxHeights[j] );
                sum += heights[j];
            }

            for(int k=i+1;k<n;k++){
                heights[k] = min( heights[k-1], maxHeights[k] );
                sum += heights[k];
            }

            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};
