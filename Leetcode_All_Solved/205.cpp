//separates check & update maps.

//NOTE: bijection (one-to-one and onto)
//NOTE: injection (one-to-one)
//NOTE: surjection (onto)
//NOTE: so shall have 2 maps for 2 directions.
#define notyet (-1)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<char> s2t;
    vector<char> t2s;

    inline bool good(const char& s, const char& t){
        bool g1 = s2t[s] == notyet || s2t[s] == t;
        bool g2 = t2s[t] == notyet || t2s[t] == s;
        return g1 && g2;
    }

    bool isIsomorphic(string s, string t) {
        s2t.resize(128, notyet);
        t2s.resize(128, notyet);

        for(int i=0;i<s.size();i++){
            if(!good(s[i], t[i])) return false;

            //separates check and updating maps
            if(s2t[s[i]] == notyet) s2t[s[i]] = t[i];
            if(t2s[t[i]] == notyet) t2s[t[i]] = s[i];
        }

        return true;
    }
};
