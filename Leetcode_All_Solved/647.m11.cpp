//m11
//recursion with memo
#define notyet (-1)
class Solution {
public:
    int cnt = 0;
    vector<vector<int>> memo;
    bool is_palin(const string& s, const int& i, const int& j){
        if(!(i<=j)) return true;
        if(memo[i][j] != notyet) return memo[i][j];

        //NOTE: must enumerate (i+1, j) (i, j-1) too.
        is_palin(s, i+1, j);
        is_palin(s, i, j-1);
        bool inner = is_palin(s, i+1, j-1);
        if(s[i] == s[j] && inner){
            cnt++;
            return memo[i][j] = true;
        }else return memo[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n, notyet));
        is_palin(s, 0, n-1);
        return cnt;
    }
};
