class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(const string& s: logs){
            if(s[0] == '.' && s[1] == '.' && depth != 0) depth--;
            else if(s[0] != '.') depth++;
        }
        
        return depth;
    }
};
