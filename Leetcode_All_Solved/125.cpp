#include<ctype.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j){
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;

            if(isalpha(s[i])) s[i] = tolower(s[i]);
            if(isalpha(s[j])) s[j] = tolower(s[j]);
            if(s[i++] != s[j--]) return false;
        }

        return true;
    }
};
