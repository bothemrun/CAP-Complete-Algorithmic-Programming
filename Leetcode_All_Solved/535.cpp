//m0
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
    unordered_map<string, string> long2short, short2long;
    int cnt = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long2short.count(longUrl) != 0) return long2short[longUrl];

        string shortUrl = to_string(cnt++);
        long2short[longUrl] = shortUrl;
        short2long[shortUrl] = longUrl;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
