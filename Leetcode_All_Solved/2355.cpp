//m0
//O(n) monotonic stack variant + dp

#define strict_fewer(i) (books[i] - i)
#define arithmetic_progression(a, b) ( (long long)(a+b) * (long long)(b-a+1) / (long long)2 )

#include<algorithm>
#include<stack>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();

        //NOTE: dp[i] := max books ending at i and taking all books[i] at i
        vector<long long> dp(n);
        //NOTE: monotonic stack of indices
        stack<int> mono;

        for(int i=0;i<n;i++){
            while(
                mono.size() &&
                !( strict_fewer( mono.top() ) < strict_fewer(i) )
            ){
                mono.pop();
            }


            long long len = i - ( (mono.size())? mono.top():(-1) );
            //NOTE: trap
            long long len_above0 = len;
            if(books[i] - (len-1) < 0) len_above0 = books[i];
            

            dp[i] = len_above0 * (long long)books[i] - arithmetic_progression(0, len_above0 - 1);

            if(mono.size()) dp[i] += dp[ mono.top() ];

            //update
            mono.push(i);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
