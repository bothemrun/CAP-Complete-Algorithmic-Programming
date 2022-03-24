class Solution {
private:
    vector<string> append_combi(const vector<string>& tmp_ans, const vector<char>& append_letters){
        vector<string> ans;
        for(string s:tmp_ans){
            for(char c:append_letters) ans.push_back(s+c);
        }
        return ans;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<char> m[9+1];
        int n_letter = 0;
        for(int i=2;i<=9;i++){
            for(int j=0;j<3;j++){
                m[i].push_back('a' + (n_letter++));
                if('s' == 'a' + n_letter) j--;
            }
        }
        m[9].push_back('z');
        
        vector<int> digits_int;
        for(int i=0;i<digits.size();i++) digits_int.push_back( digits.at(i) - '0' );
        
        vector<string> ans;
        if(digits == "") return ans;
        ans.push_back("");
        for(int i=0;i<digits_int.size();i++){
            vector<string> tmp_ans (ans);
            ans = append_combi(tmp_ans, m[digits_int.at(i)]);
        }
        
        return ans;
    }
};
