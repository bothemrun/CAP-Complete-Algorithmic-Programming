//O(n)
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
    string lastNonEmptyString(string s) {
        int n = s.size();

        vector<int> cnt(256, 0);
        int max_cnt = 0;
        int max_cnt_cnt = 0;
        for(const char& c: s){
            cnt[c]++;

            if(cnt[c] > max_cnt){
                max_cnt = cnt[c];
                max_cnt_cnt = 1;
            }else if(cnt[c] == max_cnt){
                max_cnt_cnt++;
            }
        }

        string ans = "";
        for(int i=n-1;i>=0;i--)if( max_cnt == cnt[ s[i] ] ){
            cnt[s[i]]--;
            max_cnt_cnt--;

            ans += s[i];

            if(max_cnt_cnt <= 0) break;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
