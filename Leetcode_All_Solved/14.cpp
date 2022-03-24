class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs.at(0).size();i++){
            for(int j=1;j<strs.size();j++){
                if(i >= strs.at(j).size() || strs.at(0).at(i) != strs.at(j).at(i)) return ans;
            }
            ans += strs.at(0).at(i);
        }
        return ans;
    }
};
