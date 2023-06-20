#define comb(n) ( ( (n)*(n+1) ) / 2 ) //wrong: ( (n*(n+1)) / 2 )
class Solution {
public:
    int countLetters(string s) {
        int ans = 0;
        int n = s.size();
        int start=0;
        while(start<n){
            //window of same char, [start, end]
            int end = start;
            while(end+1<n && s[start] == s[end + 1]) end++;
            
            ans += comb( end - (start-1) );

            //update
            start = end + 1;
        }

        return ans;
    }
};
