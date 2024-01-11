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
    int numberOfSpecialSubstrings(string s) {
        int n = s.size();

        int ans = 0;
        bool has[256] = {0};
        //window [i, j]
        int j=(-1);
        for(int i=0;i<n;i++){
            while(j+1<n && has[ s[j+1] ] == false){
                j++;
                has[ s[j] ] = true;
            }

            ans += j - (i-1);

            //update, drop
            has[ s[i] ] = false;

            j = max(j, i);
        }

        return ans;
    }
};
