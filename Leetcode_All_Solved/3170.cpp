//m0
//instead of using heap in O(nlogn),
//O(26*n), 
//and probably without the 26 constant, due to "min_char".

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        const char removed_char = '#';
        const int alphabet = 26;

        vector<vector<int>> char2pos(alphabet);
        const char no_min_char = 'z' + 1;
        char min_char = no_min_char;

        for(int i=0;i<n;i++){
            if(s[i] != '*'){
                char2pos[ s[i] - 'a' ].push_back(i);

                min_char = min(min_char, s[i]);
            }else{
                //assert(min_char != no_min_char);
                //assert(char2pos[ min_char-'a' ].size() != 0);

                int pos = char2pos[ min_char-'a' ].back();
                char2pos[ min_char-'a' ].pop_back();

                s[pos] = removed_char;

                if(char2pos[ min_char-'a' ].size() == 0){
                    do{
                        min_char++;
                    }while(min_char != no_min_char && char2pos[ min_char-'a' ].size() == 0);
                }
            }
        }

        string ans = "";
        for(const char& c: s)if(c != removed_char && c != '*'){
            ans += c;
        }
        return ans;
    }
};
