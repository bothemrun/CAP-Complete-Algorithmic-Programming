//O(n/k * k) = O(n)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        //can't init ans = 0;
        int ans = INT_MIN;
        for(int d=0;d<k;d++){
            int sum = 0;
            for(int i = n-1 - d;i>=0;i -= k){
                sum += energy[i];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
