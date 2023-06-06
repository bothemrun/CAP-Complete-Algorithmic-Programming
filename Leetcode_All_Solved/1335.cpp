//m0
//recursion with memo. enumerate this partition.
#define notyet INT_MAX
#define none INT_MAX
#include<limits.h>
#include<algorithm>
#include<assert.h>

class Solution {
public:
    vector<vector<int>> memo;

    int partition(const vector<int>& job, const int& i, const int& part){
        assert(i>=0);
        if(part == 1) return memo[i][part] = *max_element(job.begin(), job.begin() + i+1);

        int len = i - (0-1);
        if(len < part) return none;

        if(memo[i][part] != notyet) return memo[i][part];

        int ret = none;
        //NOTE: enumerate this partition's front end
        for(int j=0+part-1;j<=i;j++){
            int tmp = partition(job, j-1, part-1);
            if(tmp == none) continue;

            ret = min(
                ret,
                tmp + *max_element(job.begin() + j, job.begin() + i+1)
            );
        }

        return memo[i][part] = ret;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        //1-indexed for partition count
        memo.resize(n, vector<int>(d + 1, notyet));

        int ret = partition(jobDifficulty, n-1, d);
        return (ret==none)? (-1):ret;
    }
};
