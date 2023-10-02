//O(n)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        vector<int> cnt(2, 0);

        int i = 0;
        while(i<n){
            //same color window [i, j]
            int j = i;
            while(j+1<n && colors[j+1] == colors[i]) j++;

            int len = j - (i-1);
            if(len >= 3)
                cnt[ colors[i] - 'A' ] += len-2;
            
            //update
            i = j+1;
        }

        //NOTE: no ">=", since Alice plays first.
        return cnt[0] > cnt[1];
    }
};
