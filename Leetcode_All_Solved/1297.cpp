//O(maxSize * n) = O(26n)
//optimized from O(maxSize^2 * n)

#include<unordered_map>
#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();

        unordered_map<string, int> s2f;

        int uni = 0;
        int cnt[256] = {0};
        //[i, j] window
        int j=(-1);

        for(int i=0;i<n;i++){
            //update, add
            while(j+1<n && (
                cnt[s[j+1]] > 0 ||
                ( cnt[s[j+1]] == 0 && uni+1 <= maxLetters )
            ) ){
                j++;

                if(cnt[s[j]]++ == 0){
                    uni++;
                }
            }

            assert(i<=j);
            int len = j - (i-1);
            if(len >= minSize){
                //optim: from O(maxSize^2 * n) to O(maxSize * n)
                string sub = s.substr(i, minSize - 1);//minSize >= 1
                for(int l=minSize; l <= min(maxSize, len) ;l++){
                    int right = i + (l-1);
                    if(!(right < n)) break;

                    //update, add
                    sub += s[right];
                    s2f[sub]++;
                }
            }

            //update, drop
            assert( --cnt[s[i]] >= 0 );
            if(cnt[s[i]] == 0) uni--;
        }


        int max_f = 0;
        for(const auto& [s, f]: s2f){
            max_f = max(max_f, f);
        }

        return max_f;
    }
};
