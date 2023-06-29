class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1. count times of 26 chars
        // resize, init as 0
        vector<int> times_s (26, 0);
        vector<int> times_t (26, 0);
        count_times(s, times_s);
        count_times(t, times_t);
        
        // 2. compare the 2 times
        for(int i=0;i<times_s.size();i++){
            if(times_s.at(i) != times_t.at(i)) return false;
        }//for i
        // include the case of empty string ""
        return true;
    }//
    
    void count_times(string& st, vector<int>& times){
        for(int i=0;i<st.size();i++){
            ( times.at( (int)(st.at(i) - 'a') ) )++;
        }//for i
    }//
};
