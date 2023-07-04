//m1
//recursion with memo O(n^2).
//generalized k non-empty palindrome partition
#define Part 3
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

    vector<vector<int>> memo;
    bool enum_partition(const string& s, const int& i, const int& part){
        if(i==n) return part == 0;
        if(part > n - i) return false;
        if(part == 1) return memo[i][part] = is_palin(s, i, n-1);

        if(memo[i][part] != notyet) return memo[i][part];

        for(int j=i;j<n;j++)if(is_palin(s, i, j)){
            if(enum_partition(s, j+1, part - 1) == true)
                return memo[i][part] = true;
        }
        return memo[i][part] = false;
    }

    bool checkPartitioning(string s) {
        n = s.size();
        palin_memo.resize(n, vector<int>(n, notyet));

        //partition count 1-based
        memo.resize(n, vector<int>(Part + 1, notyet));
        return enum_partition(s, 0, Part);
    }
};
