//m0
//brute force, O( (n - ab) * ab )

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
    int n, a, b, ab;
    
    unordered_map<string, int> word2cnt;
    inline bool check(const string& s, const int& start) const{

        unordered_map<string, int> cnt;
        for(int i=0;i<a;i++)
            cnt[ s.substr(start + i*b, b) ]++;
        
        if(cnt.size() != word2cnt.size()) return false;

        for(const auto& [key, val]: word2cnt)if(cnt[key] != val) return false;
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size();
        a = words.size();
        b = words.back().size();
        ab = a * b;

        for(const string& word: words)
            word2cnt[word]++;


        vector<int> ans;
        for(int i=0;(i + ab-1)<n;i++)
            if(check(s, i)) ans.push_back(i);
        return ans;
    }
};
