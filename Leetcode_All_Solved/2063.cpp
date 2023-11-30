//O(n)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long countVowels(string word) {
        long long n = word.size();

        bool vowel[256] = {0};
        vowel['a'] = true;
        vowel['e'] = true;
        vowel['i'] = true;
        vowel['o'] = true;
        vowel['u'] = true;

        long long ans = 0;
        for(long long i=0;i<n;i++)if( vowel[ word[i] ] == true){
            ans += (i - (-1LL)) * (n-1LL - (i-1LL));
        }
        return ans;
    }
};
