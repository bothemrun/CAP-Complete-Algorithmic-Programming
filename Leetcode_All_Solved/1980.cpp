#include<unordered_set>
#include<assert.h>

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> num_set;
        for(const string& x: nums)
            num_set.insert(x);
        
        string s = "";
        for(int i=0;i<n;i++) s += '0';
        if(num_set.count(s) == 0) return s;

        for(int i=0;i<n;i++){
            s[i] = '1';
            if(num_set.count(s) == 0) return s;
            s[i] = '0';
        }

        assert(false);
        return "";
    }
};
