//m0
//recursion with memo. O(nd)

#define notyet (-1)
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
    int d;
    vector<int> memo;
    int jump_back_forth(const vector<int>& arr, const int& x){
        if(memo[x] != notyet) return memo[x];

        int ret = 1;
        for(int sign=(-1);sign<=1;sign+=2){
            for(int delta=1;delta<=d;delta++){
                int y = x + sign * delta;
                if(!(0<=y && y<n)) break;
                
                if(!( arr[x] > arr[y] )) break;

                ret = max(
                    ret,
                    1 + jump_back_forth(arr, y)
                );
            }
        }

        return memo[x] = ret;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        this->d = d;

        memo.resize(n, notyet);
        
        int ans = 1;
        for(int i=0;i<n;i++)
            ans = max(
                ans,
                jump_back_forth(arr, i)
            );
        return ans;
    }
};
