//m0
//O(n^2) shrink dp wisdompeak interval II

class Solution {
public:
    const int notyet = (-1);
    vector<vector<int>> memo;

    int shrink(const string& s, int i, int j){
        if(i>j) return 0;
        if(i==j) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        if(s[i] == s[j]){
            return memo[i][j] = shrink(s, i+1, j-1);
        }else{
            //either add another s[i] or s[j]
            return memo[i][j] = 1 + min(
                shrink(s, i+1, j),
                shrink(s, i, j-1)
            );
        }
    }

    int minInsertions(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n, notyet));

        return shrink(s, 0, n-1);
    }
};
