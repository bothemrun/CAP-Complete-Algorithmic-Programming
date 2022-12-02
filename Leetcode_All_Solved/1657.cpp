#include<algorithm>
class Solution {
public:
    inline void count(string word, vector<int>& cnt){
        for(char c: word) cnt[(int)(c - 'a')]++;
    }
    inline bool check_alphabet(vector<int>& cnt1, vector<int>& cnt2){
        for(int i=0;i<cnt1.size();i++)
            if( cnt1[i]==0 ^ cnt2[i]==0 ) return false;
        return true;
    }
    inline bool check_group_freq(vector<int>& cnt1, vector<int>& cnt2){
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        for(int i=0;i<cnt1.size();i++)
            if(cnt1[i] != cnt2[i])return false;
        return true;
    }
    bool closeStrings(string word1, string word2) {
        //NOTE: operation 1 permits reordering --> sorting
        //NOTE: operation 2 checks frequencies of groups
        //NOTE: but finally they got to have the same alphabet
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        count(word1, cnt1);
        count(word2, cnt2);
        
        if(check_alphabet(cnt1, cnt2) == false)return false;
        if(check_group_freq(cnt1, cnt2) == false)return false;
        return true;
    }
};
