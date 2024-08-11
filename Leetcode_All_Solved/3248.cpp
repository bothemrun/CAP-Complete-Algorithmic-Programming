class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0, j=0;
        for(const string& s: commands){
            if(s[0]=='U') i--;
            else if(s[0]=='D') i++;
            else if(s[0]=='R') j++;
            else j--;//L
        }
        return i*n + j;
    }
};
