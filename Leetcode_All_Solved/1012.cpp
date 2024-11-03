//similar to 2376 Count Special Integers hard

//O(max count of digits * mask * dup bool * digits) 
//= O(log1e9 * 2^10 * 2 * 10) = 30*1e3*2e1 = 6e6

//edge case:
//1. [1, n] no 0.
//2. leading 0s.
//solution: the same as 2376.

class Solution {
public:
    vector<int> digits;

    const int notyet = (-1);
    vector<vector<vector<vector<int>>>> memo;
    int digit_dp(int i, int mask, bool tight, bool dup){
        if(i==(-1)) return dup==true;

        if(memo[i][mask][tight][dup] != notyet) return memo[i][mask][tight][dup];

        int ret = 0;
        int bound = (tight)? digits[i]:9;
        for(int digit=0;digit<=bound;digit++){
            int new_mask = (digit==0 && mask==0)? 0:(mask | (1<<digit));
            //leading 0s
            bool new_dup = (new_mask==0)? false:(
                (mask & ( 1<<digit ) ) != 0
            );
            ret += digit_dp(i-1, new_mask, tight && digit==bound, dup || new_dup );
        }

        return memo[i][mask][tight][dup] = ret;
    }
    int numDupDigitsAtMostN(int n) {
        int x = n;
        while(x>0){
            digits.push_back(x%10);
            x /= 10;
        }

        memo.resize(digits.size(), vector<vector<vector<int>>>(1<<10, vector<vector<int>>(2, vector<int>(2, notyet) ) ) );
        return digit_dp((int)digits.size()-1, 0, true, false);
    }
};
