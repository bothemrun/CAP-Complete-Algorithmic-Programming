#include<algorithm>
#include<unordered_set>

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt = 0;
        unordered_map<string, int> prefix_hash;
        for(string& word: words){
            if(prefix_hash.count(word) != 0) 
                cnt += prefix_hash[word];
            
            reverse(word.begin(), word.end());
            prefix_hash[word]++;
        }
        return cnt;
    }
};
