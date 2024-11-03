//digit dp + bitmask

//tricky:
//(1) [1, n] no 0.
//(2) leading 0s
//--> solution: leading 0s not marked, but in-between 0s are marked

//O(count of digit * bitmask * range of digits) = O(log2e9 * 2^10 *10) = 30 * 1e3 * 1e1 = 3e5

class Solution {
public:
    vector<int> digits;

    const int notyet = (-1);
    vector<vector<vector<int>>> memo;
    int digit_dp(int i, int mask, bool tight){
        if(i==(-1)) return (mask>>1) != 0;//[1, n], no 0

        if(memo[i][mask][tight] != notyet) return memo[i][mask][tight];

        int ret = 0;
        int bound = (tight)? digits[i]:9;
        for(int digit=0;digit<=bound;digit++){
            //leading 0s not marked, but in-between 0s are marked
            if( (mask & (1<<digit)) != 0) continue;

            int new_mask = (digit==0 && mask==0)? 0:(mask | (1<<digit));
            ret += digit_dp(i-1, new_mask, tight && digit == bound);
        }
        return memo[i][mask][tight] = ret;
    }

    int countSpecialNumbers(int n) {
        int x = n;
        while(x>0){
            digits.push_back(x%10);
            x /= 10;
        }

        memo.resize(digits.size(), vector<vector<int>>(1<<10, vector<int>(2, notyet) ) );
        return digit_dp((int)digits.size()-1, 0, true);
    }
};
