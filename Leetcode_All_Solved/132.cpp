//recursion with memo. O(n^2)
#define notyet (-1)
#include<limits.h>
#include<algorithm>
class Solution {
public:
    int n;
    vector<vector<int>> palin_memo;
    bool is_palin(const string& s, const int& i, const int& j){
        //NOTE: includes length == 2
        if(i>=j) return true;

        if(palin_memo[i][j] != notyet) return palin_memo[i][j];

        return palin_memo[i][j] = (s[i] == s[j])? is_palin(s, i+1, j-1):false;
    }

    vector<int> memo;
    int enum_partition(const string& s, const int& i){
        if(i==n) return 0;

        if(memo[i] != notyet) return memo[i];

        int min_cut = INT_MAX;
        for(int j=i;j<n;j++)if(is_palin(s, i, j))
            min_cut = min(
                min_cut,
                1 + enum_partition(s, j+1)
            );
        return memo[i] = min_cut;
    }

    int minCut(string s) {
        n = s.size();

        palin_memo.resize(n, vector<int>(n, notyet));
        memo.resize(n, notyet);
        return enum_partition(s, 0) - 1;
    }
};
