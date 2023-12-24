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
    int minOperations(string s) {
        int n = s.size();

        int flip = 0;
        for(int i=0;i<n;i++){
            if(i%2 != s[i] - '0') flip++;
        }

        return min(flip, n-flip);
    }
};
