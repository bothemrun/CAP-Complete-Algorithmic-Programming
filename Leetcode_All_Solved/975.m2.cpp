//m2

//O(E) = O(V) = O(n)
//overall O(nlogn)

//[A] vector of bool:
//https://stackoverflow.com/questions/28882959/operator-on-stdvectorbool

//[B] must group the even & odd jumping in 1 for loop.

#define tii tuple<int,int>
#include<functional>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> jump(n, vector<int>(2, false));
        jump.back()[0] = true;
        jump.back()[1] = true;

        map<int,int> suf_m;
        for(int i=n-1;i>=0;i--){
            auto it1 = suf_m.lower_bound(arr[i]);
            if(it1 != suf_m.end()){
                jump[i][1] |= jump[ it1->second ][0];
            }

            auto it2 = suf_m.upper_bound(arr[i]);
            if(it2 != suf_m.begin()){
                jump[i][0] |= jump[ prev(it2)->second ][1];
            }

            //update
            //for both cases, smallest index first.
            suf_m[ arr[i] ] = i;
        }

        int ans = 0;
        for(int i=0;i<n;i++) ans += jump[i][1];
        return ans;
    }
};
