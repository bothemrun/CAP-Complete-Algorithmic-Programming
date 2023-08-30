//m0
//for the complexity of the naive backtracking, T(n) = (n-2) * T(n-2) = (n-2) * (n-4) * ... = n!! factoriail
//with memo, O( 2^(n/2) ), which is better than factorial.
//for both of the complexity, need to be multiplied with n, for making substrings

#include<unordered_map>

class Solution {
public:
    unordered_map<string, bool> memo;

    bool enum_flip(string state){
        if(memo.count(state) != 0) return memo[state];

        int n = state.size();
        for(int i=0;i+1<n;i++)if(
            state[i] == '+' &&
            state[i+1] == '+' &&
            enum_flip(
                state.substr(0, i) + "-" +
                state.substr(i+2)
            ) == false
        ) return memo[state] = true;

        return memo[state] = false;
    }

    bool canWin(string currentState) {
        return enum_flip(currentState);
    }
};
