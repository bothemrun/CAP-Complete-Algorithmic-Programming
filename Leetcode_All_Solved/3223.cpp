static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumLength(string s) {
        int cnt[256] = {0};
        for(char c: s) cnt[c]++;

        int ans = (int)s.size();
        for(char c='a';c<='z';c++)if(cnt[c] >= 3){
            if(cnt[c]%2 == 0) ans -= cnt[c] - 2;
            else ans -= cnt[c] - 1;
        }
        return ans;
    }
};
