#include<stdlib.h>
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> char2pos(26);
        for(int i=0;i<keyboard.size();i++)
            char2pos[(int)(keyboard[i] - 'a')] = i;
        int cost = 0;
        int cur_pos = 0;
        for(char c: word){
            cost += abs( char2pos[(int)(c - 'a')] - cur_pos );
            cur_pos = char2pos[(int)(c - 'a')];
        }
        return cost;
    }
};
