//digit dp in O(logn)
//dp(i, sum, tight) has better cache locality than dp(i, tight, sum)

class Solution {
public:
    const int notyet = (-1);
    vector<vector<vector<int>>> memo;
    vector<int> digits;
    int digit_dp(int i, int sum, bool tight){
        if(i<0) return sum;

        if(memo[i][sum][tight] != notyet) return memo[i][sum][tight];

        int bound = (tight==true)? digits[i]:9;
        int ret = 0;
        for(int d=0;d<=bound;d++){
            ret += digit_dp(i-1, sum + (d==1), tight & d==bound);
        }
        return memo[i][sum][tight] = ret;
    }
    int countDigitOne(int n) {
        //edge case
        if(n == 0) return 0;
        while(n > 0){
            digits.push_back(n%10);
            n /= 10;
        }

        memo.resize( (int)digits.size(), vector<vector<int>>(10+1, vector<int>(2, notyet) ) );
        return digit_dp( (int)digits.size()-1, 0, true );
    }
};
