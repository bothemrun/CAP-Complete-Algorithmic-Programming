//m2
//NOTE: optim by pruning. 
//if zero/one count doesn't fit, then dp value the same. --> so 3D to 2D array.
#define none INT_MIN
#define Memo_plus(x, y) ( (memo[x][y]==none)? none:(memo[x][y] + 1) )

#include<limits.h>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m+1, vector<int>( n+1, none ));
        memo[0][0] = 0;
        int l = strs.size();
        for(int i=0;i<l;i++){
            int cnt0 = 0, cnt1 = 0;
            for(const char& c: strs[i])
                (c=='0')? cnt0++:cnt1++;
            
            //NOTE: prune, reverse order
            for(int zero=m;zero>=cnt0;zero--)
                for(int one=n;one>=cnt1;one--)
                    memo[zero][one] = max(
                        memo[zero][one],
                        Memo_plus(zero-cnt0, one-cnt1)
                    );
        }

        //NOTE: edge case: for zero < cnt0
        int max_subset = 0;
        for(int zero=0;zero<=m;zero++)
            for(int one=0;one<=n;one++)
                max_subset = max(
                    max_subset,
                    memo[zero][one]
                );
        return max_subset;
    }
};
