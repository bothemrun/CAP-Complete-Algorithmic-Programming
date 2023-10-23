//Thinking Process:

//[A] Dimension Reduction with Pre-compuation:

//1. for any range sum problems, we can pre-compute prefix sums to get range sums in O(1).
//2. so pre-compute prefix sums for each row.


//[B] Think About the 1D Problem:

//1. now we can get a range sum for any row in O(1).
//2. so fix two column borders, then turned into a 1D problem.


//[C] in 1D, find max range sum <= k:

//1. without the condition of <= k, we can do this with prefix min in O(1 * m).
//2. therefore, we do this with an tree set in O(mlogm)
//3. can't use binary search 'cuz it has negative numbers.
//4. can't use a min heap 'cuz we need to binary search the conditions of <= k.


//[D] summary

//1. O(n * n * mlogm)
//2. if(n >>> m), transpose the matrix.

#define range_sum(i, x, y) ( (x==0)? prefix_sum[i][y]:( prefix_sum[i][y] - prefix_sum[i][x-1] ) )

#include<algorithm>
#include<set>
#include<limits.h>
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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix.back().size();

        //no overflow
        vector<vector<int>> prefix_sum(m, vector<int>(n));
        for(int i=0;i<m;i++){
            vector<int>& ps = prefix_sum[i];

            ps.front() = matrix[i].front();
            for(int j=1;j<n;j++)
                ps[j] = ps[j-1] + matrix[i][j];
        }


        //int max_sum = matrix.front().front();
        int max_sum = INT_MIN;

        //fix 2 column borders
        for(int x=0;x<n;x++)
            for(int y=x;y<n;y++){
                //NOTE: prefix tree set
                set<int> prefix_set;

                //NOTE: sum all forwards
                prefix_set.insert(0);

                //no overflow
                int col_prefix_sum = 0;

                for(int i=0;i<m;i++){
                    col_prefix_sum += range_sum(i, x, y);

                    auto it = prefix_set.lower_bound( col_prefix_sum - k );
                    
                    if(it != prefix_set.end()){
                        assert(col_prefix_sum - *it <= k);

                        max_sum = max(
                            max_sum,
                            col_prefix_sum - *it
                        );
                    }

                    //update
                    prefix_set.insert(col_prefix_sum);
                }
            }
        
        return max_sum;
    }
};
