#include<algorithm>
class Solution {
public:
    void backtrack(vector<string>& ans, string& ans1, const vector<vector<char>>& option, const int& i=0){
        if(i == option.size()){
            ans.push_back(ans1);
            return;
        }

        for(const char& c: option[i]){
            ans1 += c;
            backtrack(ans, ans1, option, i+1);
            ans1.erase(ans1.size()-1, 1);
        }
    }
    vector<string> expand(string s) {
        vector<vector<char>> option;
        bool bracket = false;
        for(int i=0;i<s.size();i++){
            if(s[i] == '{'){
                bracket = true;

                //NOTE:
                option.push_back({});

            }else if(s[i] == '}'){
                bracket = false;

                sort(option.back().begin(), option.back().end());
            }else if(bracket == false){
                option.push_back( {s[i]} );
            }else if(bracket == true && s[i] != ','){
                option.back().push_back(s[i]);
            }
        } 
        cout << "here\n";

        vector<string> ans;
        string ans1 = "";
        backtrack(ans, ans1, option);
        return ans;
    }
};
