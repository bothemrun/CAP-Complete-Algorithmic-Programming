//O(nlogn) due to sorting

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
    int minDeletions(string s) {
        int cnt[256] = {0};
        for(const char& c: s) cnt[c]++;

        vector<int> freq;
        for(const int& cn: cnt)if(cn != 0) freq.push_back(cn);

        sort(freq.begin(), freq.end());

        int ans = 0;
        
        for(int i=(int)freq.size() - 2;i>=0;i--)if( freq[i] >= freq[i+1] ){

            if(freq[i+1] == 0){
                ans += freq[i];
                freq[i] = 0;
            }else{
                int new_freq = freq[i+1] - 1;
                ans += freq[i] - ( new_freq );
                freq[i] = new_freq;
            }
        }

        return ans;
    }
};
