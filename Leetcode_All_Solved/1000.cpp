//m0
//recursion with memo. enumerate this partition.
//pruning by remainder of (k-1), since partition from 1 to k costs much more.
#define notyet INT_MAX
#define none INT_MAX
#define add(x, y) ((x==none || y==none)? none:(x+y))
#define range_sum(i, j) ((i==0)? prefix[j]:(prefix[j] - prefix[i-1]) )
#include<algorithm>
#include<limits.h>
#include<assert.h>

class Solution {
public:
    vector<vector<vector<int>>> memo;
    int k;
    vector<int> prefix;

    int partition(const vector<int>& stones, const int& low, const int& high, const int& part){
        assert(low<=high && low>=0);

        int len = high - (low-1);
        if( (len - part)%(k-1) != 0) return none;

        if(len == part) return 0;

        if(memo[low][high][part] != notyet) return memo[low][high][part];

        if(part == 1) return memo[low][high][part] = add(
            range_sum(low, high),
            partition(stones, low, high, k)
        );

        int ret = none;
        //NOTE: enumerate this partition
        for(int j=low + part-1;j<=high;j++)
            ret = min(
                ret,
                add(
                    partition(stones, low, j-1, part-1),
                    partition(stones, j, high, 1)
                )
            );
        return memo[low][high][part] = ret;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        this->k = k;

        prefix.resize(n);
        prefix.front() = stones.front();
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + stones[i];

        //1-indexed for partition count
        memo.resize(n, vector<vector<int>>(n, vector<int>(k + 1, notyet) ) );

        int ret = partition(stones, 0, n-1, 1);
        return (ret==none)? (-1):ret;
    }
};
