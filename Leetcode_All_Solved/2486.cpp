//O(max(S, T))
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        int i=0;
        for(int j=0;j<n;j++){
            while(i<m && s[i] != t[j]){
                i++;
            }

            if(!(i<m)){
                return n - j;
            }

            i++;//used s[i]
        }

        return 0;
    }
};
