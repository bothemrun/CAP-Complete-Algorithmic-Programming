class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int cnt = 0;
        int L = 0, R = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'L')L++;
            else R++;

            if(L == R){
                cnt++;
                L = 0;
                R = 0;
            }
        }
        return cnt;
    }
};
