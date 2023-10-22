//O(n * log(S / (k+1)) ) binary search the answer
//, where S := sum(sweetness)

//it sounds like a partition DP problem.
//but with O(n * k * n) complexity, so no.

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
    inline bool valid(const vector<int>& sweetness, const int& k, const int& min_sum){
        //NOTE: greedy check: just add the remaining entries to the last partition.

        int partition = k+1;
        int sum = 0;//no overflow
        for(int i=0;i<n;i++){
            sum += sweetness[i];

            if(sum >= min_sum){
                sum = 0;
                partition--;

                if(partition==0) return true;
            }
        }

        return false;
    }

    int binary(const vector<int>& sweetness, const int& k, const int& low, const int& high){
        int mid = low + (high-low)/2;
        bool mid_valid = valid(sweetness, k, mid);
        if(mid_valid && valid(sweetness, k, mid+1)==false) return mid;
        if(low == high) assert(false);

        if(mid_valid) return binary(sweetness, k, mid+1, high);
        else return binary(sweetness, k, low, mid);
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        n = sweetness.size();
        int all_sum = 0;//no overflow
        for(const int& x: sweetness)
            all_sum += x;
        
        return binary(sweetness, k, 1, all_sum / (k+1) + 1 );
    }
};
