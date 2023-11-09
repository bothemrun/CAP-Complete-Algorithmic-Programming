#define arithmetic(x, y) ( (x+y) * (y-(x-1)) / 2LL )
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countHomogenous(string s) {
        long long n = s.size();
        long long cnt = 0;
        const long long mod = (long long)1e9 + 7;
        long long i=0;
        while(i<n){
            //[i, j] homogeneous
            long long j = i;
            while(j+1<n && s[i] == s[j+1]){
                j++;
            }

            long long len = j - (i-1);
            cnt = (
                cnt +
                arithmetic(1, len)
            )%mod;

            //update
            i = j+1;
        }

        return cnt;
    }
};
