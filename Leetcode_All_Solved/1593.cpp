#include<algorithm>
#include<unordered_set>
class Solution {
public:
    int max_uni = 0;
    void backtrack(const string& s, unordered_set<string>& uni, const int& low=0, const int& high=0){
        if(high == s.size()){
            if(low == s.size())
                max_uni = max(max_uni, (int)uni.size());
            return;
        }

        //1. not split here
        backtrack(s, uni, low, high+1);

        //2 split here
        string sub = s.substr(low, high - (low-1) );
        if(uni.count(sub) != 0)return;
        uni.insert(sub);
        backtrack(s, uni, high+1, high+1);
        uni.erase(sub);
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> uni;
        backtrack(s, uni);
        return max_uni;
    }
};
