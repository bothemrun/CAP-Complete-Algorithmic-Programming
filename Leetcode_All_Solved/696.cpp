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
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> group;
        int i = 0;
        while(i<n){
            int left = i;
            while( i+1<n && s[left] == s[i+1] ) i++;
            int len = i - (left-1);
            if(s[left] == 0)
                group.push_back( -len );
            else group.push_back( len );

            //update
            i++;
        }

        int cnt = 0;
        int g = group.size();
        for(int i=0;i<g-1;i++){
            int mi = min(
                group[i],
                group[i+1]
            );

            cnt += mi;
        }

        return cnt;
    }
};
