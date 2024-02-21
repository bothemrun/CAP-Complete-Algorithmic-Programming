class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int cnt[26] = {0};
        for(char c: words.front()) cnt[c-'a']++;

        for(const string& w: words){
            int cnt1[26] = {0};
            for(char c: w) cnt1[c-'a']++;

            for(char c='a';c<='z';c++)
                cnt[c-'a'] = min(cnt[c-'a'], cnt1[c-'a']);
        }

        vector<string> ans;
        for(char c='a';c<='z';c++)
            for(int i=0;i<cnt[c-'a'];i++){
                string ans1 = "";
                ans1 += c;
                ans.push_back(ans1);
            }
        
        return ans;
    }
};
