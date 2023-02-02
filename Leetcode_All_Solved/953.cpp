#include<algorithm>
#include<unordered_map>
class Solution {
public:
    unordered_map<char,int> char2order;
    inline bool less_equal(const string& a, const string& b){
        int n = min((int)a.size(), (int)b.size());
        int i;
        for(i=0;i<n;i++){
            if(a[i] != b[i])break;
        }
        if(i == n)return a.size() <= b.size();
        return char2order[a[i]] <= char2order[b[i]];
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++)
            char2order[order[i]] = i;
        
        for(int i=0;i<words.size()-1;i++){
            if(less_equal(words[i], words[i+1]) == false)
                return false;
        }
        return true;
    }
};
