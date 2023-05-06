//m2
//direct dp method, not lcss. recursion with memo
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int scss(const string& a, const string& b, const int& i, const int&j){
        if(i==0 || j==0) return memo[i][j] = (j==0)? i:j;

        if(memo[i][j] != notyet) return memo[i][j];

        //strings 1-indexed
        if(a[i-1] == b[j-1]) return memo[i][j] = 1 + scss(a, b, i-1, j-1);
        return memo[i][j] = 1 + min(
            scss(a, b, i-1, j),
            scss(a, b, i, j-1)
        );
    }

    void scss_backtrack(const string& a, const string& b, const int& i, const int& j, string& scss_res){
        if(i==0 || j==0){
            string tmp = (j==0)? a.substr(0, i-1+1):b.substr(0, j-1+1);
            reverse(tmp.begin(), tmp.end());
            scss_res += tmp;
            return;
        }

        //strings 1-indexed
        if(a[i-1] == b[j-1]){
            scss_res += a[i-1];
            return scss_backtrack(a, b, i-1, j-1, scss_res);
        }
        
        if(memo[i-1][j] < memo[i][j-1]){
            scss_res += a[i-1];
            scss_backtrack(a, b, i-1, j, scss_res);
        }else{
            scss_res += b[j-1];
            scss_backtrack(a, b, i, j-1, scss_res);
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        memo.resize(m + 1, vector<int>(n + 1, notyet));
        scss(str1, str2, m, n);

        string scss_res = "";
        scss_backtrack(str1, str2, m, n, scss_res);
        reverse(scss_res.begin(), scss_res.end());
        return scss_res;
    }
};
