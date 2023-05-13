//m0
//recursion with memo
#define notyet (-1)
#define mod ((int)1e9 + 7)
class Solution {
public:
    int low_idx, high_idx, zero, one;
    vector<int> memo;
    int enum_suffix(const int& todo_i){
        int done_i = todo_i - 1;
        int this_in = low_idx <= done_i && done_i <= high_idx;
        //no further
        if(!(todo_i <= high_idx)) return this_in;

        if(memo[todo_i] != notyet) return memo[todo_i];

        return memo[todo_i] = (
            this_in +
            enum_suffix(todo_i + one) +
            enum_suffix(todo_i + zero)
        )%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        this->low_idx = low-1;
        this->high_idx = high-1;
        this->zero = zero;
        this->one = one;
        memo.resize(high, notyet);

        return enum_suffix(0);
    }
};
