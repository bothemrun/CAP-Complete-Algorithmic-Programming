class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            if(words[i].size() > n)return false;
            for(int j=0;j<words[i].size();j++){
                if(i >= words[j].size())return false;
                if(words[i][j] != words[j][i] )return false;
            }
        }
        return true;
    }
};
