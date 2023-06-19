#include<stdlib.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int delta = 0;
        for(const vector<int>& shi: shift)
            delta += ((shi[0]==1)? 1:(-1)) * shi[1];
        
        //NOTE: crucial
        //wrong: delta %= s.size();
        delta %= (int)s.size();

        if(delta <= 0)
            return s.substr(-delta) + s.substr(0, -delta);
        else return s.substr((int)s.size()-delta) + s.substr(0, (int)s.size()-delta);
    }
};
