//m1
//use another logic for inserting / deleting 1 char.

//O(n), instead of O(n^2) edit distance dp.
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
        while(i<m && j<n){
            if(s[i] != t[j]){
                if(++skip > 1) return false;
                i++;
            }else{
                i++;
                j++;
            }
        }

        //NOTE: trailing
        assert(j==n);
        if(i==m-1) return skip == 0;

        assert(i==m && skip <= 1);
        return true;
    }
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if(m==n){
            int diff = 0;
            for(int i=0;i<m;i++)if(s[i] != t[i]){
                if(++diff > 1) return false;
            }

            return diff == 1;
        }else if(m==n+1)
            return insert1(s, t);
        else if(m+1==n)
            return insert1(t, s);
        else return false;
    }
};
