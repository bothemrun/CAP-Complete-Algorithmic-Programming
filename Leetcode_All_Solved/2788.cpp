#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> ans;

    inline void split(const string& s, const string& delim){
        int start = 0, end;
        while((end = s.find(delim, start)) != string::npos){
            if(start != end){
                ans.push_back( s.substr(start, (end-1) - (start-1) ) );
            }

            start = end + delim.size();
        }

        if(start<(int)s.size()) ans.push_back( s.substr(start) );
    }

    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {

        string delim = "";
        delim += separator;
        
        for(const string& s: words){
            split(s, delim);
        }

        return ans;
    }
};
