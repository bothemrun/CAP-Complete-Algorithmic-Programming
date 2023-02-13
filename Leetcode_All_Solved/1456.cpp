#include<unordered_set>
#include<algorithm>
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});
        int max_win = 0;
        int n = s.size();

        int win = 0;
        for(int i=0;i<k;i++)if( vowel.count(s[i]) != 0 ) win++;

        for(int i=0;i-1+k < n;i++){
            if(i != 0){
                if( vowel.count(s[i-1]) != 0 )
                    win--;
                if( vowel.count(s[i-1+k]) != 0 )
                    win++;
            }

            max_win = max(max_win, win);
        }

        return max_win;
    }
};
