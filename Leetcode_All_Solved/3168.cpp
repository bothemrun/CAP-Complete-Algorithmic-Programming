class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int cur = 0;
        for(const char c: s){
            if(c=='E') cur++;
            else cur--;

            ans = max(ans, cur);
        }
        return ans;
    }
};
