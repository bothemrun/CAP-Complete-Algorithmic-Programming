//m2
//recursion with memo, optim by reducing half of the states from [n][2] to [n] memo.
#define notyet (-1)
class Solution {
public:
    int n;
    vector<long long> memo;
    long long q_or_not(const vector<vector<int>>& questions, const int& i){
        if(!(i<n)) return 0;

        if(memo[i] != notyet) return memo[i];

        return memo[i] = max(
            q_or_not(questions, i+1),
            q_or_not(questions, i + questions[i][1] + 1) +
            questions[i][0]
        );
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memo.resize(n, notyet);
        return q_or_not(questions, 0);
    }
};
