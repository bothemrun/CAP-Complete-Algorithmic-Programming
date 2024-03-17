class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        for(const char& ch: s)if(ch == c){
            cnt++;
        }
        
        return cnt*(cnt+1)/2LL;
    }
};
