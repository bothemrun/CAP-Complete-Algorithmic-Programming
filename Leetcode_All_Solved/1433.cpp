#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    inline bool check(const string& s1, const string& s2){
        for(int i=0;i<n;i++)if(s1[i] < s2[i])
            return false;
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        n = s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return check(s1, s2) || check(s2, s1);
    }
};
