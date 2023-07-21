//m0
//recursion with memo.

#define notyet (-1)
#define mod ((int)1e9 + 7)
#define MOD(x) ( (x>=mod)? (x-mod):x ) 

class Solution {
public:
    int one, zero;

    vector<int> memo;
    int choose_which(const int& i){
        if(i==0) return 1;
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        return memo[i] = MOD(
            choose_which(i - zero) +
            choose_which(i - one)
        );
    }

    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        one = oneGroup;
        zero = zeroGroup;

        //1-indexed
        memo.resize(maxLength + 1, notyet);

        int cnt = 0;
        for(int i=minLength;i<=maxLength;i++){
            cnt = MOD(
                cnt +
                choose_which(i)
            );
        }

        return cnt;
    }
};
