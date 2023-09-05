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
    int n;
    inline bool sort_parity(const string& s1, const string& s2, const int& base){
        int cnt[256] = {0};
        for(int i=base;i<n;i+=2) cnt[ s1[i] ]++;

        for(int i=base;i<n;i+=2)if( cnt[ s2[i] ]-- == 0 ) return false;
        return true;
    }

    bool canBeEqual(string s1, string s2) {
        this->n = s1.size();

        return sort_parity(s1, s2, 0) && sort_parity(s1, s2, 1);
    }
};
