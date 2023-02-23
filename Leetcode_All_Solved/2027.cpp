class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        while(i < n){
            if(s[i] == 'O'){
                i++;
                continue;
            }

            cnt++;
            i += 3;
        }

        return cnt;
    }
};
