#include<limits.h>
#include<unordered_map>
#include<algorithm>
#include<stdlib.h>
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        unordered_map<string, vector<int>> word2idx;
        for(int i=0;i<n;i++){
            if(word2idx.count(words[i]) == 0){
                word2idx[ words[i] ] = vector<int>( {i} );
            }else{
                word2idx[ words[i] ].push_back(i);
            }
        }
        
        if(word2idx.count(target) == 0){
            return (-1);
        }
        
        int min_d = INT_MAX;
        for(const int& idx: word2idx[ target ]){
            min_d = min( min_d, abs(idx - startIndex) );
            if(startIndex <= idx){
                min_d = min(min_d, startIndex + n - idx );
            }else{
                min_d = min(min_d, idx + n - startIndex );
            }
        }
        return min_d;
    }
};
