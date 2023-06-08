#define offset 1000
#define memosize (2*offset+3)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt[memosize] = {0};
        for(const int& a: arr) cnt[offset+a]++;
        
        bool freq[offset+3] = {0};
        for(const int& c: cnt)if(c != 0){
            if(freq[c] == true) return false;
            freq[c] = true;
        }
        return true;
    }
};
