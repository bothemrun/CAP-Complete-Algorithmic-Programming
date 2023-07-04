//m0
//recursion with memo. O(n^2). 
//for each i, can we cut the remaining string into 2 palin?
#define notyet (-1)
class Solution {
public:
    int n;
    vector<vector<int>> palin_memo;
    bool is_palin(const string& s, const int& i, const int& j){
        //NOTE: includes len 2
        if(i>=j) return true;

        if(palin_memo[i][j] != notyet) return palin_memo[i][j];

        return palin_memo[i][j] = (s[i] == s[j])? is_palin(s, i+1, j-1):false;
    }

    bool checkPartitioning(string s) {
        n = s.size();
        palin_memo.resize(n, vector<int>(n, notyet));
        //[0, i] [i+1, j] [j+1, n-1]
        for(int i=0;i+2<n;i++)if(is_palin(s, 0, i))
            for(int j=i+1;j+1<n;j++)if(is_palin(s, i+1, j)){
                if(is_palin(s, j+1, n-1)) return true;
            }
        return false;
    }
};
