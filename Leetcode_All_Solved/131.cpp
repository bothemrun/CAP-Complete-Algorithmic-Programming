class Solution {
private:
    inline bool palindrome(const string& s, int s_begin, int s_end){
        //[s_begin, s_end]
        while(s_begin < s_end){
            if(s[s_begin] == s[s_end]){
                s_begin++;
                s_end--;
            }else return false;
        }
        return true;
    }
    void backtrack(const string& s, vector<vector<string>>& ans, vector<string>& cur_ans, int s_begin=0){
        if(s_begin == s.size()){
            ans.push_back(cur_ans);
            return;
        }
        
        for(int i=s_begin;i<s.size();i++){
            if(palindrome(s, s_begin, i) == true){
                cur_ans.push_back(s.substr(s_begin, i-s_begin+1));
                backtrack(s, ans, cur_ans,  i + 1);
                cur_ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur_ans;
        
        backtrack(s, ans, cur_ans);
        return ans;
    }
};
