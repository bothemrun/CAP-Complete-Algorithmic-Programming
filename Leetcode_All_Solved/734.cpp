#define delim "##"
#include<unordered_set>
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size())
            return false;
        
        unordered_set<string> sim;
        for(const vector<string>& p: similarPairs){
            sim.insert(p[0] + delim + p[1]);
            sim.insert(p[1] + delim + p[0]);
        }
        
        for(int i=0;i<sentence1.size();i++){
            if(sentence1[i] != sentence2[i]  && 
                sim.count(sentence1[i] + delim + sentence2[i]) == 0)
                return false;
        }
        return true;
    }
};
