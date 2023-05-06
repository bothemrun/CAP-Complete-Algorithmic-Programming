//m1
//longest common subsequence, bottom up dp
#include<algorithm>
class Solution {
public:
    void lcss_backtrack(const string& a, const string& b, const int& i, const int& j, string& lcss_res, const vector<vector<int>>& memo){
        if(i==0 || j==0) return;

        //strings 1-indexed
        if(a[i-1] == b[j-1]){
            lcss_res += a[i-1];
            return lcss_backtrack(a, b, i-1, j-1, lcss_res, memo);
        }
        (memo[i-1][j] > memo[i][j-1])?
            lcss_backtrack(a, b, i-1, j, lcss_res, memo):
            lcss_backtrack(a, b, i, j-1, lcss_res, memo);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1));
        for(int i=0;i<=m;i++) memo[i][0] = 0;
        for(int j=0;j<=n;j++) memo[0][j] = 0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                //strings 1-indexed
                if(str1[i-1] == str2[j-1]) memo[i][j] = 1 + memo[i-1][j-1];
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1] );
            }
        
        string lcss_res = "";
        lcss_backtrack(str1, str2, m, n, lcss_res, memo);
        reverse(lcss_res.begin(), lcss_res.end());


        string scss = "";
        int i=0, j=0;
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
