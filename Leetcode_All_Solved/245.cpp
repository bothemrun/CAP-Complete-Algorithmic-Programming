#include<algorithm>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int min_dist = INT_MAX;
        int last_idx1 = INT_MIN, last_idx2 = INT_MIN;
        if(word1 == word2){
            for(int i=0;i<n;i++){
                if(wordsDict[i] == word1){
                    if(last_idx1 >= 0)
                        min_dist = min(min_dist, abs(i - last_idx1) );
                    
                    last_idx1 = i;
                }
            }
        }else{
            for(int i=0;i<n;i++){
                if(wordsDict[i] == word1)
                    last_idx1 = i;
                if(wordsDict[i] == word2)
                    last_idx2 = i;
                
                if(last_idx1 >= 0 && last_idx2 >= 0)
                    min_dist = min(min_dist, abs(last_idx1 - last_idx2));
            }
        }

        assert(min_dist != INT_MAX);
        return min_dist;
    }
};
