class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int i=0, n=words.size();
        for(const char& c: s){
            if(!(i<n)) return false;
            if(words[i++][0] != c) return false;
        }
        return i==n;
    }
};
