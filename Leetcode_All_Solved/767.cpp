#define PIC pair<int, char>
#include<queue>
#include<algorithm>
#include<utility>

class Solution {
public:
    string reorganizeString(string s) {
        int cnt[256] = {0};
        for(const char& c: s) cnt[c]++;

        auto cmp_lam = [](const PIC& a, const PIC& b){
            return a.first < b.first;//max heap
        };
        priority_queue<PIC, vector<PIC>, decltype(cmp_lam)> maxheap(cmp_lam);
        
        for(char c='a';c<='z';c++)if(cnt[c] > 0) maxheap.push( PIC(cnt[c], c) );


        //NOTE: greedy
        string ans = "";
        char last_char = 'A';
        while(maxheap.size() >= 2){
            auto [cnt1, c1] = maxheap.top();
            maxheap.pop();
            auto [cnt2, c2] = maxheap.top();
            maxheap.pop();

            if(last_char == c1){
                swap(cnt1, cnt2);
                swap(c1, c2);
            }

            ans += c1;

            if(--cnt1 > 0){
                maxheap.push( PIC(cnt1, c1) );
            }
            maxheap.push( PIC(cnt2, c2) );

            last_char = c1;
        }

        if(maxheap.size() == 0) return ans;

        //edge case
        if(maxheap.top().first == 1 && maxheap.top().second != last_char) return ans + maxheap.top().second;

        return "";
    }
};
