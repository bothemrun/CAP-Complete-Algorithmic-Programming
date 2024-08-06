#define tic tuple<int, char>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumPushes(string word) {
        int cnt[256] = {0};
        for(char c: word) cnt[c]++;

        vector<tic> cnt2c;
        for(char c='a';c<='z';c++)if(cnt[c] != 0) cnt2c.push_back(tic(cnt[c], c));
        sort(cnt2c.begin(), cnt2c.end(), greater<tic>() );

        int push = 0;
        int i=0;
        for(const auto& [count, _]: cnt2c){
            push += (i/8 + 1) * count;

            i++;
        }
        return push;
    }
};
