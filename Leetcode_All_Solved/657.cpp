#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0, y=0;
        for(const char& c: moves){
            if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='L') x--;
            else x++;
        }
        return x==0 && y==0;
    }
};
