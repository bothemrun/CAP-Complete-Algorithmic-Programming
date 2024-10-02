//m1
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int cnt[256] = {0};

        int right = (-1);//[left, right] good
        for(int left=0;left<n;left++){
            right = max(right, left-1);
            while(right+1<n && cnt[s[right + 1]] + 1 <= 1 ){
                cnt[s[++right]]++;
            }

            //s[left] is always valid
            ans = max(ans, right - (left-1));

            //update
            assert(--cnt[s[left]] >= 0);
        }
        return ans;
    }
};
