class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int m = s.size();
        int i=0;

        int n = words.size();
        int j=0, k=0;
        while(j<n){
            if(s[i] != words[j][k]) return false;

            if(++i == m) return k+1 == words[j].size();

            if(++k == words[j].size()){
                j++;
                k = 0;
            }
        }
        return false;
    }
};
