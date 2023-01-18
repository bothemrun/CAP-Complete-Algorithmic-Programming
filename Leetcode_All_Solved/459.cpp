class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=0;i<n/2;i++)if(n % (i+1) == 0){
            int len = i+1;
            string sub = s.substr(0, len);

            bool match = true;
            for(int j=len;j<n;j+=len){
                if(sub != s.substr(j, len)){
                    match = false;
                    break;
                }
            }
            if(match)return true;
        }

        return false;
    }
};
