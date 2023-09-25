//O(n) by monotonic stack

//1. left[i] := prefix sum of heights if the peak is at i
//1.1. right[i] := suffix sum of heights if the peak is at i

//2. use the 132 / last smaller property of monotonic stack
//2.1. let j := the index of the last smaller
//2.2. left[i] = left[j] + maxHeights[i] * (i - j)
//2.3. that is, fill leftwards until meeting the last smaller of maxHeights

#include<algorithm>
#include<stack>
#include<stdlib.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    inline void monotonic_stack_last_smaller(const vector<int>& maxHeights, const int& begin, const int& end, const int& delta, vector<long long>& sum_peak){

        //of index, not value
        stack<int> last_smaller;

        for(int i=begin; delta*i <= delta*end; i += delta){

            while(
                last_smaller.size() != 0 &&
                !( maxHeights[ last_smaller.top() ] < maxHeights[i] )
            ){
                last_smaller.pop();
            }

            if(last_smaller.size() != 0){
                int j = last_smaller.top();
                
                sum_peak[i] = sum_peak[j] + (long long)maxHeights[i] * (long long)abs(i - j);
            }else{
                sum_peak[i] = (long long)maxHeights[i] * (long long)( abs(i - begin) + 1 );
            }

            last_smaller.push(i);
        }
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();

        //prefix monotonic stack, last smaller
        vector<long long> prefix_peak(n);
        monotonic_stack_last_smaller(maxHeights, 0, n-1, 1, prefix_peak);

        //suffix monotonic stack, next smalelr
        vector<long long> suffix_peak(n);
        monotonic_stack_last_smaller(maxHeights, n-1, 0, -1, suffix_peak);


        long long max_sum = 0;
        for(int i=0;i<n;i++)
            max_sum = max(
                max_sum,
                prefix_peak[i] + suffix_peak[i] - (long long)maxHeights[i]
            );
        return max_sum;
    }
};
