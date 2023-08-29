#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    //prefix sum of 'Y'
    vector<int> prefixsum;

    inline int rangesum(const int& low, const int& high){
        //[low, high]
        if(high == (-1)) return 0;
        if(low == n) return 0;

        assert(high < n);
        assert(low <= high);
        if(low == 0) return prefixsum.at(high);
        else return prefixsum.at(high) - prefixsum.at(low-1);
    }

    int bestClosingTime(string customers) {
        n = customers.size();
        prefixsum.resize(n);
        
        prefixsum.front() = customers.front() == 'Y';
        for(int i=1;i<n;i++){
            //prefixsum[i] = prefixsum[i-1] + customers[i] == 'Y';
            //NOTE: operator precedence
            prefixsum[i] = prefixsum[i-1] + ( customers[i] == 'Y' );
        }


        int min_penalty = n + 3;
        int min_penalty_j = (-1);
        for(int j=0;j<=n;j++){
            int penalty =
                ( j - rangesum(0, j-1) ) + 
                rangesum(j, n-1);
            
            if(penalty < min_penalty){
                min_penalty = penalty;
                min_penalty_j = j;
            }
        }

        return min_penalty_j;
    }
};
