#include<unordered_map>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowel_sorted = {
            'A', 'E', 'I', 'O', 'U',
            'a', 'e', 'i', 'o', 'u'
        };
        unordered_map<char, int> vowel2cnt;
        for(const char& c: vowel_sorted) vowel2cnt[c] = 0;

        for(const char& c: s)if(vowel2cnt.count(c) != 0) vowel2cnt[c]++;

        const int vsize = vowel_sorted.size();
        int i = 0;
        if(!(i < vsize)) return s;

        for(char& c: s)if(vowel2cnt.count(c) != 0){
            char v = vowel_sorted[i];

            while( vowel2cnt[ v ] == 0){
                i++;
                assert(i < vsize);
                v = vowel_sorted[i];
            }

            c = v;
            vowel2cnt[ v ]--;
            assert( vowel2cnt[v] >= 0 );
        }

        return s;
    }
};
