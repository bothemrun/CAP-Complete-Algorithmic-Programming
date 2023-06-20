#define alphabet 26
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[alphabet] = {0};
        for(const char& c: s) cnt[c - 'a']++;

        int odd_cnt = 0;
        for(const int& c: cnt)if(c%2==1){
            if(++odd_cnt > 1) return false;
        }
        return true;
    }
};
