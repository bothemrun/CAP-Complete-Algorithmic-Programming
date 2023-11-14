//m0

//[B] Other Methods in the Solutions: O(26*n):

//1. for each 26 char, between the char's first & last occurrence,
//2. use a hash set for count the number of unique chars in between.
//3. this is O(26*n).

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        const int alphabet = 26;
        const int no_occur = (-1);
        vector<int> first(alphabet, no_occur);
        vector<int> last(alphabet, no_occur);
        for(int i=0;i<n;i++){
            if(first[ s[i]-'a' ] == no_occur)
                first[ s[i]-'a' ] = i;
            
            last[ s[i]-'a' ] = i;
        }

        int ans = 0;//no overflow, since 26^3 = 1e4
        for(char c='a';c<='z';c++){
            if(first[c-'a'] == no_occur) continue;

            int cnt[26] = {0};

            for(int i=first[c-'a'] + 1;i < last[c-'a'];i++)
                cnt[ s[i]-'a' ]++;
            
            for(int i=0;i<26;i++)if(cnt[i] != 0)
                ans++;
        }

        return ans;
    }
};
