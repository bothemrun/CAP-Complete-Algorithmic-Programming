#include<unordered_map>
class Solution {
public:
    inline string encode(const string& word){
        vector<int> cnt(26, 0);
        for(int i=0;i<word.size();i++){
            cnt[ (int)(word[i] - 'a') ] = 1;
        }
        
        string code = "";
        for(int i=0;i<26;i++)if(cnt[i] != 0){
            code += (char)('a' + i);
        }
        return code;
    }
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        unordered_map<string, int> prefix;
        for(const string& word: words){
            string code = encode(word);
            if(prefix.count(code) != 0){
                cnt += prefix[code];
                //not count self
                
                //update
                prefix[code]++;
            }else prefix[code] = 1;//update
        }
        return cnt;
    }
};
