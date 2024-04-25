//m0
//time complexity O(NL), L := alphabet size.
//bottom up costs O(L) space.
//top down costs O(NL) space.

#define alphabet 26
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int k, n;

    vector<vector<int>> pos;
    const int no_pos = (-1);

    vector<int> memo;
    const int notyet = (-1);

    int enum_end_at(const string& s, int i){
        assert(i>=0);

        if(memo[i] != notyet) return memo[i];

        int ret = 1;
        for(int d=(-k);d<=k;d++){
            int ch = s[i] - 'a' + d;

            if(ch<0) continue;
            if(!(ch<alphabet)) break;

            if(pos[i][ch] == no_pos) continue;

            ret = max(
                ret,
                1 + enum_end_at(s, pos[i][ch])
            );
        }

        return memo[i] = ret;
    }

    int longestIdealString(string s, int k) {
        n = s.size();
        this->k = k;

        pos.resize(n, vector<int>(alphabet));
        //pos[0].resize(alphabet, no_pos);
        for(int ch=0;ch<alphabet;ch++) pos[0][ch] = no_pos;

        for(int i=1;i<n;i++){
            //vector deep copy
            pos[i] = pos[i-1];

            pos[i][ s[i-1] - 'a' ] = i-1;
        }


        memo.resize(n, notyet);
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(
                ans,
                enum_end_at(s, i)
            );

        return ans;
    }
};
