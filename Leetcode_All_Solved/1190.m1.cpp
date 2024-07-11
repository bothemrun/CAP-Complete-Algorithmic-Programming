//m1

class Solution {
public:
    string reverseParentheses(string s) {
        string sta = "";
        vector<int> left_paren;

        for(const char& c: s){
            if(c=='('){
                left_paren.push_back(sta.size());
            }else if(c==')'){
                reverse(sta.begin() + left_paren.back(), sta.end() );
                left_paren.pop_back();
            }else{
                sta += c;
            }
        }
        return sta;
    }
};
