#include<ctype.h>
#include<algorithm>
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int max_val = 0;
        for(const string& str: strs){
            bool has_alpha = false;
            for(const char& c: str){
                if(isalpha(c)){
                    max_val = max(max_val, (int)str.size());
                    has_alpha = true;
                    break;
                }
            }
            
            if(has_alpha == false){
                max_val = max(max_val, stoi(str));
            }
        }
        return max_val;
    }
};
