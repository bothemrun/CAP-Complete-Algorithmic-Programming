//m3
//NOTE: optim by pruning. optim with fast init by array 0
//if zero/one count doesn't fit, then dp value the same. --> so 3D to 2D array.

#define none (-100)
#define val_offset 100
#define offset_value(x) (x + val_offset)
#define real_value(x) (x - val_offset) 
#define max_n 100
#define none_plus1(offset_x) ( (offset_x == offset_value(none))? offset_x:(offset_x + 1) )

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
        //NOTE: fast init to 0 by array, with value offset
        int memo[max_n + 1][max_n + 1] = {0};

        memo[0][0] = offset_value(0);

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
                        none_plus1( memo[zero - cnt0][one - cnt1] )
                    );
        }

        //NOTE: edge case: for zero < cnt0
        int max_subset = offset_value(0);
        for(int zero=0;zero<=m;zero++)
            for(int one=0;one<=n;one++)
                max_subset = max(
                    max_subset,
                    memo[zero][one]
                );
        return real_value(max_subset);
    }
};
