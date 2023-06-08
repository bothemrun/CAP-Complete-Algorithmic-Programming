#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string reverseVowels(string s) {
        int vowel[128] = {0};
        vowel['a'] = true;
        vowel['e'] = true;
        vowel['i'] = true;
        vowel['o'] = true;
        vowel['u'] = true;
        vowel['A'] = true;
        vowel['E'] = true;
        vowel['I'] = true;
        vowel['O'] = true;
        vowel['U'] = true;

        int n = s.size();
        int i=0, j=n-1;
        while(i<j){
            while(i<n && !( vowel[ s[i] ] ) ) i++;
            while(j>=0 && !( vowel[ s[j] ] ) ) j--;
            if(!(i<j)) return s;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
