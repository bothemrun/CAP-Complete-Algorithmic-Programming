//m0

//[A] distinct decision tree:

//1. 4 cases for the outer chars.
//2. define dp(i, j, a) := not necessarily have to use [i] & [j].

//3. the transition by cases further extends the distinct decision tree, ensured by recursion/dp definition:

/*
dp(i, j, a) = {
    a + {dp(next+1, prev-1, non-a)} + a, (1)

    //no {dp(next+1, prev-1, a)}, (2)
    //(2.1) --> what about these smaller a*a (* is non-a palin)?  counted by (1).
    //(2.2) --> what about these smaller a*a (* is a palin)?  counted by (3).

    a + {dp(next+1, prev-1, a)} + a, (3)

    a + {null} + a, (4)
    //--> double aa, since dp doesn't count null as 1

    single a (5) 
    //--> the above all wraps 2 outer a.
}
*/


//[B] implement

//1. can be simplified to dp(i, j).

#define mod ((int)1e9 + 7)

class Solution {
public:
    unordered_map<char, int> idx = {
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3}
    };
    vector<vector<int>> next, prev;

    const int notyet = (-1);
    vector<vector<int>> memo;

    int enum_outer_decision_tree(const string& s, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;

        if(memo[i][j] != notyet) return memo[i][j];

        int ret = 0;
        for(int a=0;a<(int)idx.size();a++){
            //wraps 2 outer a
            //if no a, then n > (-1)
            if(next[i][a] < prev[j][a]){
                //also for i+1 == j, length 2
                ret = (
                    ret                   +enum_outer_decision_tree(s, next[i][a] + 1, prev[j][a] - 1)
                    +1
                )%mod;
            }

            if(next[i][a] <= j){
                ret = (ret+1)%mod;
            }
        }

        return memo[i][j] = ret;
    }

    int countPalindromicSubsequences(string s) {
        int n = s.size();

        next.resize(n, vector<int>(idx.size()));
        for(int a=0;a<(int)idx.size();a++){
            int a_i = 0;
            for(int i=0;i<n;i++){
                a_i = max(a_i, i);

                while(a_i<n && idx[ s[a_i] ] != a){
                    a_i++;
                }

                next[i][a] = a_i;//n means null
            }
        }

        prev.resize(n, vector<int>(idx.size()));
        for(int a=0;a<(int)idx.size();a++){
            int a_i = n-1;
            for(int i=n-1;i>=0;i--){
                a_i = min(a_i, i);

                while(a_i>=0 && idx[ s[a_i] ] != a){
                    a_i--;
                }

                prev[i][a] = a_i;//(-1) means null
            }
        }

        memo.resize(n, vector<int>(n, notyet));

        return enum_outer_decision_tree(s, 0, n-1);
    }
};
