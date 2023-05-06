//m3
//direct dp method, not lcss. bottom up dp.
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    void scss_backtrack(const string& a, const string& b, const int& i, const int& j, string& scss_res){
        if(i==0 || j==0){
            string tmp = (j==0)? a.substr(0, i-1+1):b.substr(0, j-1+1);
            reverse(tmp.begin(), tmp.end());
            scss_res += tmp;
            return;
        }

        //all strings 1-indexed
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
        memo.resize(m + 1, vector<int>(n + 1));
        for(int i=0;i<=m;i++) memo[i][0] = i;
        for(int j=0;j<=n;j++) memo[0][j] = j;

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                //strings 1-indexed
                if(str1[i-1] == str2[j-1]) memo[i][j] = 1 + memo[i-1][j-1];
                else memo[i][j] = 1 + min(memo[i-1][j], memo[i][j-1] );
            }
        

        string scss_res = "";
        scss_backtrack(str1, str2, m, n, scss_res);
        reverse(scss_res.begin(), scss_res.end());
        return scss_res;
    }
};
