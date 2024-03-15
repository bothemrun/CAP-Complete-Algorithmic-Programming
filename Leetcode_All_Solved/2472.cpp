//m0
//O(n^2)
//wisdompeak's Basic Type II or Interval Type I dp.
//the is_palindrome(i, j) part is Interval Type II.

#include<algorithm>

class Solution {
public:
    const int notyet = (-1);
    vector<vector<int>> palin_memo;

    bool is_palin_shrink(const string& s, const int& left, const int& right){
        if(!(left <= right)) return true;

        if(palin_memo[left][right] != notyet) return palin_memo[left][right];

        if(s[left] == s[right]){
            return palin_memo[left][right] = is_palin_shrink(s, left+1, right-1);
        }else return palin_memo[left][right] = false;
    }

    vector<int> memo;
    int enum_last_partition(const string& s, const int& k, const int& i){
        if(!(i>=0)) return 0;

        if(memo[i] != notyet) return memo[i];

        int ma = 0;
        //[j, i] last partition
        for(int j=i;j>=0;j--){
            int len = i - (j-1);

            int add = 0;

            if(len >= k && is_palin_shrink(s, j, i) == true){
                add = 1;
            }

            ma = max(
                ma,
                add + enum_last_partition(s, k, j-1)
            );
        }

        return memo[i] = ma;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        palin_memo.resize(n, vector<int>(n, notyet));

        memo.resize(n, notyet);
        return enum_last_partition(s, k, n-1);
    }
};
