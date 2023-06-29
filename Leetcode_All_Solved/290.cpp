#include<unordered_map>
class Solution {
public:
    inline void split(const string& s, vector<string>& splits, const string& delim){
        int start = 0, end;
        while( (end = s.find(delim, start)) != string::npos){
            splits.push_back(s.substr(start, (end-1) - (start-1) ));
            start = end + delim.size();
        }
        if(start<s.size()) splits.push_back(s.substr(start));
    }

    bool wordPattern(string pattern, string s) {
        vector<string> splits;
        split(s, splits, " ");

        if(splits.size() != pattern.size()) return false;


        const string notyet = "";
        vector<string> p2s(256, notyet);
        unordered_map<string, char> s2p;

        for(int i=0, n=pattern.size();i<n;i++){
            char p = pattern[i];
            string word = splits[i];

            if( p2s[p]==notyet && s2p.count(word)==0 ){
                p2s[p] = word;
                s2p[word] = p;
            }else if( p2s[p]==word && s2p[word]==p ) continue;
            else return false;
        }

        return true;
    }
};
