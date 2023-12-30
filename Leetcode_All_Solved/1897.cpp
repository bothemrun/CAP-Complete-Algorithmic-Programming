class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int cnt[256] = {0};
        for(const string& w: words)
            for(char c: w)
                cnt[c]++;
        
        for(char c='a';c<='z';c++)if(cnt[c]%n != 0)
            return false;
        return true;
    }
};
