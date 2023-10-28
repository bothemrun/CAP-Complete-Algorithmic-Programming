//m0
//[A] try fixing 1 index.

//[B] try fixing k
//1. the choices of i depends on j, so O(n^3)

//[C] try fixing the middle j
//1. the choices of i & k don't depend on each other. so O(n^2)  possible
//2. can be done in O(n) with traversing the prefix & suffix.

//O(n^2)
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();

        const int none = INT_MIN;
        int max_sum = none;
        for(int j=1;j<n-1;j++){

            int front_max = none;
            for(int i=0;i<j;i++)if(prices[i] < prices[j])
                front_max = max(front_max, profits[i] );
            
            int back_max = none;
            for(int k=j+1;k<n;k++)if(prices[j] < prices[k])
                back_max = max(back_max, profits[k] );
            
            if(front_max != none && back_max != none)
                max_sum = max(max_sum, front_max + profits[j] + back_max);
        }

        return (max_sum==none)? (-1):max_sum;
    }
};
