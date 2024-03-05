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
    int minimumLength(string s) {
        int n = s.size();
        int i=0, j=n-1;
        while(i<j && s[i] == s[j]){
            char c = s[i];
            while(i<=j && s[i]==c){
                i++;
            }
            while(i<=j && s[j]==c){
                j--;
            }
        }

        return j - (i-1);
    }
};
