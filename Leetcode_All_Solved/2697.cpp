#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i] != s[j])
                (s[i] > s[j])? (s[i]=s[j]):(s[j]=s[i]);
            i++;
            j--;
        }
        return s;
    }
};
