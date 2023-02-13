//m1
//unordered_set to vector set
//#include<unordered_set>
#include<algorithm>
class Solution {
public:
    int maxVowels(string s, int k) {
        //unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});
        vector<bool> vowel(26, false);
        vowel['a' - 'a'] = true;
        vowel['e' - 'a'] = true;
        vowel['i' - 'a'] = true;
        vowel['o' - 'a'] = true;
        vowel['u' - 'a'] = true;
        
        int max_win = 0;
        int n = s.size();

        int win = 0;
        //for(int i=0;i<k;i++)if( vowel.count(s[i]) != 0 ) win++;
        for(int i=0;i<k;i++)if( vowel[ s[i] - 'a'] ) win++;

        for(int i=0;i-1+k < n;i++){
            if(i != 0){
                //if( vowel.count(s[i-1]) != 0 )
                if( vowel[ s[i-1] - 'a'] )
                    win--;
                //if( vowel.count(s[i-1+k]) != 0 )
                if( vowel[ s[i-1+k] - 'a'] )
                    win++;
            }

            max_win = max(max_win, win);
        }

        return max_win;
    }
};
