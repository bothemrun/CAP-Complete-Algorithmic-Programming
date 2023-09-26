//m0
//1. for char[i], if we have char[i] later, and char[i] > [i+1], then discard char[i]

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        int cnt[256] = {0};
        for(const char& c: s) cnt[c]++;
        bool used[256] = {0};

        string ans = "";
        for(const char& c: s){
            cnt[c]--;

            //NOTE: if used before, then all chars after it must be greater that it,
            //NOTE: otherwise it would already have been popped.
            if(used[c] == true) continue;

            while(
                ans.size() != 0 &&
                cnt[ ans.back() ] != 0 &&
                ans.back() > c
            ){
                used[ ans.back() ] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            used[c] = true;
        }

        return ans;
    }
};
