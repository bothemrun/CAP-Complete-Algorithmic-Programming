class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();

        //NOTE: edge: all same, so swap 2 same chars
        bool prefix_has[256] = {0};
        bool swap_same = false;

        int diff = 0;
        char s_diff, g_diff;
        for(int i=0;i<n;i++){

            if(s[i] == goal[i]){
                if(prefix_has[s[i]]) swap_same = true;
                else prefix_has[s[i]] = true;

                continue;
            }

            diff++;
            if(diff==1){
                //NOTE: update s_diff g_diff only when 2 chars are different
                s_diff = s[i];
                g_diff = goal[i];
            }else if(diff==2){
                if(s_diff != goal[i] || g_diff != s[i]) return false;
            }else if(diff>2) return false;
        }

        return diff==2 || (diff==0 && swap_same);
    }
};
