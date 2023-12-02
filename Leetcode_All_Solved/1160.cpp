class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26, 0);
        for(char c: chars) cnt[c - 'a']++;

        int ans = 0;
        for(const string& s: words){
            //NOTE: deep copy of vector
            vector<int> tmp = cnt;

            bool good = true;
            for(const char& c: s)if( --tmp[c - 'a'] < 0){
                good = false;
                break;
            }

            if(good) ans += s.size();
        }
        return ans;
    }
};
