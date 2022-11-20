#include<unordered_set>
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k > s.size())return 0;
        
        unordered_set<char> repeated;
        vector<int> char2cnt(26, 0);
        for(int i=0;i<k;i++){
            if(++char2cnt[ (int)(s[i] - 'a') ] == 2)
                repeated.insert(s[i]);
        }
        
        int cnt = 0;
        for(int i=k-1;i<s.size();i++){
            if(repeated.size() == 0)cnt++;
            
            //update
            if(!(i+1 < s.size()))break;
            //delete
            int i_del = i - (k-1);
            if(--char2cnt[ (int)(s[i_del] - 'a') ] == 1)
                repeated.erase(s[i_del]);
            //add
            int i_add = i + 1;
            if(++char2cnt[ (int)s[i_add] - 'a' ] == 2)
                repeated.insert(s[i_add]);
        }
        return cnt;
    }
};
