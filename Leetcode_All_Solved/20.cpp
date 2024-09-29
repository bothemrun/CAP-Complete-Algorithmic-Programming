class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> m;
        m['('] = 1;
        m[')'] = -1;
        
        m['{'] = 2;
        m['}'] = -2;
        
        m['['] = 3;
        m[']'] = -3;
        
        vector<int> stac;
        for(char c: s){
            if(m[c] > 0) stac.push_back(m[c]);
            else{
                if(stac.size() != 0 && stac.back() + m[c] == 0){
                    stac.pop_back();
                }else return false;
            }
        }
        
        return stac.size() == 0;
    }
};
