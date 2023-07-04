//m0
//recursion with memo. O(nk).
#define notyet (-1)
#include<algorithm>
#include<assert.h>

class Solution {
public:
    int n;
    vector<vector<int>> palin_memo;
    int palin_cost(const string& s, const int& i, const int& j){
        if(i>=j) return 0;

        if(palin_memo[i][j] != notyet) return palin_memo[i][j];

        return palin_memo[i][j] = (s[i] != s[j]) + palin_cost(s, i+1, j-1);
    }

    vector<vector<int>> memo;
    int enum_partition(const string& s, const int& i, const int& part){
        if(i==n){
            assert(part == 0);
            return 0;
        }
        if(part == 1) return palin_cost(s, i, n-1);
        assert(i<n && part>1);

        if(memo[i][part] != notyet) return memo[i][part];

        int min_cost = INT_MAX;
        for(int j=i;j + part-1<n;j++)
            min_cost = min(
                min_cost,
                palin_cost(s, i, j) + enum_partition(s, j+1, part-1)
            );
        return memo[i][part] = min_cost;
    }

    int palindromePartition(string s, int k) {
        n = s.size();

        palin_memo.resize(n, vector<int>(n, notyet));

        //1-indexed for partition count
        memo.resize(n, vector<int>(k + 1, notyet));
        return enum_partition(s, 0, k);
    }
};
