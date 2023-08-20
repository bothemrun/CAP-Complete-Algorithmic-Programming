//xor: mutiplication equals division

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> arr(n);

        arr[0] = pref[0];

        for(int i=1;i<n;i++)
            arr[i] = pref[i] ^ pref[i-1];
        return arr;
    }
};
