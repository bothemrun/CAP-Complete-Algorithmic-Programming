//O(n) don't need heaps
#define PIC pair<int, char>
#include<assert.h>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int char2cnt[256] = {0};
        for(const char& c: s) char2cnt[c]++;

        vector<PIC> li;
        for(char c='a';c<='z';c++)if(char2cnt[c] != 0)
            li.push_back(PIC(char2cnt[c], c));
        //already sorted in chars

        string ans = "";
        while(li.size() >= 2){
            while(li.size() >= 2){
                auto [cnt, c] = li.back();
                li.pop_back();

                int repeat = min(cnt, repeatLimit);
                for(int i=0;i<repeat;i++)
                    ans += c;
                
                cnt -= repeat;

                if(cnt > 0){
                    assert(li.size());
                    ans += li.back().second;
                    if(--li.back().first == 0){
                        li.pop_back();
                    }

                    li.push_back(PIC(cnt, c));
                }
            }
        }

        if(li.size() == 1){
            auto [cnt, c] = li.back();
            int repeat = repeatLimit;
            if(ans.size() && ans.back() == c) repeat--;
            repeat = min(repeat, cnt);

            for(int i=0;i<repeat;i++)
                ans += c;
        }

        return ans;
    }
};
