class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> sta;
        for(const char& c: s){
            if(c==')'){
                vector<char> tmp;
                while(sta.size() && sta.back() != '('){
                    tmp.push_back(sta.back());
                    sta.pop_back();
                }

                assert(sta.size() && sta.back() == '(');
                sta.pop_back();

                for(const char& c: tmp){
                    sta.push_back(c);
                }
            }else{
                sta.push_back(c);
            }
        }

        string ans = "";
        for(const char& c: sta){
            ans += c;
        }
        return ans;
    }
};
