#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        bool vow[256] = {0};
        vow['a'] = true;
        vow['e'] = true;
        vow['i'] = true;
        vow['o'] = true;
        vow['u'] = true;

        int ans = 0;
        for(int i=left;i<=right;i++){
            ans += vow[words[i].front()] && vow[words[i].back()];
        }

        return ans;
    }
};
