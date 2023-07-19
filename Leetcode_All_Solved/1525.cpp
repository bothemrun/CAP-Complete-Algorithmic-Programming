#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char, int> l, r;
        for(const char& c: s) r[c]++;

        int good = 0;
        for(const char& c: s){
            //update: add to left, drop from right
            l[c]++;
            r[c]--;

            if(l[c] == 0) l.erase(c);
            if(r[c] == 0) r.erase(c);

            if(l.size() == r.size()) good++;
        }

        return good;
    }
};
