#include<algorithm>
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();

        vector<int> charcnt(256/2-1 + 1, 0);
        int distinct = 0;
        int max_win = 0;
        int high = 0;
        //NOTE: [low, high), consider [high]
        for(int low=0;low<n;low++){
            while(high < n && (distinct < k || charcnt[s[high]] != 0) ){
                if(charcnt[s[high]] == 0){
                    distinct++;
                }

                //include 0
                charcnt[s[high]]++;

                high++;
            }

            max_win = max(max_win, (high-1) - (low-1) );

            //update
            if(--charcnt[s[low]] == 0){
                distinct--;
            }
        }

        return max_win;
    }
};
