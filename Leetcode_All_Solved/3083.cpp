class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        unordered_set<string> uset;
        for(int i=0;i+1<n;i++) uset.insert( s.substr(i, 2) );
        
        reverse(s.begin(), s.end());
        for(int i=0;i+1<n;i++)if(uset.count( s.substr(i, 2) ) != 0){
            return true;
        }
        return false;
    }
};
