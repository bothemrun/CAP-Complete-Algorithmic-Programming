//O(n)
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int cnt[256] = {0};
        int ans = 0;

        //[i, j] window
        int j=(-1);
        for(int i=0;i<n;i++){
            j = max(j, i-1);

            while(j+1<n && cnt[ s[j+1] ] + 1 <= 2){
                cnt[ s[++j] ]++;
            }

            ans = max(ans, j - (i-1));

            //update, drop
            assert(--cnt[s[i]] >= 0);
        }

        return ans;
    }
};
