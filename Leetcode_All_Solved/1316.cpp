//m0
//O(n^2) time, max O(n^3) space theoretically.
//no rolling hash.

class Solution {
public:
    const int notyet = (-1);
    vector<vector<int>> memo;
    int same2(const string& text, int i, int j){
        if(i<0) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        if(text[i] != text[j]) return memo[i][j] = 0;
        return memo[i][j] = 1 + same2(text, i-1, j-1);
    }

    int distinctEchoSubstrings(string text) {
        int n = text.size();

        memo.resize(n, vector<int>(n, notyet));
        unordered_set<string> uset;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                const int len = j - i;

                if( same2(text, i, j) >= len ){
                    uset.insert( text.substr(i+1, len) );
                }
            }
        return uset.size();
    }
};
