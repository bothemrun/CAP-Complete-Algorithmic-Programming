class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence.back()) return false; //size>=1
        for(int i=1;i<sentence.size()-1;i++)if(sentence[i] == ' '){
            if(sentence[i-1] != sentence[i+1])return false;
        }
        return true;
    }
};
