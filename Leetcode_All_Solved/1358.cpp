#define N_CHAR 3
class Solution {
private:
    int n;
    bool get_min_window(vector<int>& win_char_cnt, int& min_window_high, const string& s){
        for(int i=min_window_high+1;i<n;i++){
            win_char_cnt[s[i] - 'a']++;
            
            bool meet = true;
            for(int j=0;j<N_CHAR;j++){
                if(win_char_cnt[j] == 0){
                    meet = false;
                    break;
                }
            }
            if(meet == true){
                min_window_high = i;
                return true;
            }
        }
        return false;
    }
public:
    int numberOfSubstrings(string s) {
        n = s.size();
        //find first window
        int min_window_high = (-1);
        vector<int> win_char_cnt(N_CHAR, 0);
        if(get_min_window(win_char_cnt, min_window_high, s) == false)return 0;
        
        //sliding window
        int ans = 0;
        for(int low=0;low<=n-3;low++){
            ans += (n-1) - (min_window_high-1);
            
            //update window
            if(--win_char_cnt[s[low]-'a'] == 0){
                if(get_min_window(win_char_cnt, min_window_high, s) == false)break;
            }
        }
        return ans;
    }
};
