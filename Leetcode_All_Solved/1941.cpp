class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[256] = {0};
        for(char c: s) cnt[c]++;

        int fix = (-1);
        for(char c='a';c<='z';c++)if(cnt[c] != 0){
            fix = cnt[c];
            break;
        }

        assert(fix != (-1));
        for(char c='a';c<='z';c++)if(cnt[c] != 0){
            if(fix != cnt[c]) return false;
        }

        return true;
    }
};
