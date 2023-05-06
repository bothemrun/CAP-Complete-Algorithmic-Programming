//m0
//longest common subsequence, recursion with memo
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int lcss(const string& a, const string& b, const int& i, const int& j){
        if(i==0 || j==0) return memo[i][j] = 0;

        if(memo[i][j] != notyet) return memo[i][j];

        //NOTE: all strings 1-indexed
        if(a[i-1] == b[j-1]) return memo[i][j] = 1 + lcss(a, b, i-1, j-1);
        return memo[i][j] = max(
            lcss(a, b, i-1, j),
            lcss(a, b, i, j-1)
        );
    }
    void lcss_backtrack(const string& a, const string& b, const int& i, const int& j, string& lcss_res){
        if(i==0 || j==0) return;

        //NOTE: all strings 1-indexed
        if(a[i-1] == b[j-1]){
            lcss_res += a[i-1];
            return lcss_backtrack(a, b, i-1, j-1, lcss_res);
        }
        (memo[i-1][j] > memo[i][j-1])?
            lcss_backtrack(a, b, i-1, j, lcss_res):
            lcss_backtrack(a, b, i, j-1, lcss_res);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        memo.resize(m+1, vector<int>(n+1, notyet));
        lcss(str1, str2, m, n);

        string lcss_res = "";
        lcss_backtrack(str1, str2, m, n, lcss_res);
        reverse(lcss_res.begin(), lcss_res.end());


        int i=0, j=0;
        string scss = "";
        for(const char& c: lcss_res){
            while(i<m && str1[i] != c) scss += str1[i++];
            i++;
            while(j<n && str2[j] != c) scss += str2[j++];
            j++;
            scss += c;
        }

        //NOTE:
        scss += str1.substr(i) + str2.substr(j);

        return scss;
    }
};
