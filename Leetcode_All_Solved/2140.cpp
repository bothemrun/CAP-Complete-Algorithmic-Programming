//recursion with memo
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<long long>> memo;
    int n;
    long long q_or_not(const vector<vector<int>>& questions, const int& i, const int& ans_this){
        if(!(i<n)) return 0;

        if(memo[i][ans_this] != notyet) return memo[i][ans_this];

        int next_q = (ans_this)? (1 + questions[i][1] ):1;
        int this_point = (ans_this)? questions[i][0]:0;
        return memo[i][ans_this] = this_point + max(
            q_or_not(questions, i+next_q, true),
            q_or_not(questions, i+next_q, false)
        );
    }
    long long mostPoints(vector<vector<int>>& questions) {
        this->n = questions.size();
        memo.resize(n, vector<long long>(2, notyet));
        return max(
            q_or_not(questions, 0, 0),
            q_or_not(questions, 0, 1)
        );
    }
};
