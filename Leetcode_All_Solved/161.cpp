//m0
//O(n), instead of edit distance dp O(n^2)
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline bool insert1(const string& s, const string& t){
        int m = s.size(), n = t.size();
        assert(m == n+1);

        //NOTE: edge: s="a", t=""
        int skip = 0;
        int i=0, j=0;
        while(i<m || j<n){
            if(j==n){
                if(i==m-1 && skip==0) return true;
                else return false;
            }else if(i==m) assert(false);
            else if(s[i] == t[j]){
                i++;
                j++;
            }else{
                if(++skip > 1) return false;
                i++;
            }
        }
        return true;
    }
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();

        if(m==n){
            int diff = 0;
            for(int i=0;i<m;i++){
                if(s[i] != t[i]){
                    if(++diff > 1) return false;
                }
            }
            return diff == 1;
        }else if(m+1==n || m==n+1){
            if(m==n+1) return insert1(s, t);
            else return insert1(t, s);
        }else return false;
    }
};
