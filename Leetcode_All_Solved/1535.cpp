//O(n)
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
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        auto it = max_element(arr.begin(), arr.end());
        int max_idx = it - arr.begin();

        if(k >= max_idx) return *it;

        //play for max_idx times
        int streak = 0;
        int front = arr.front();
        for(int t=0;t<max_idx;t++){
            int j = t + 1;
            if(front > arr[j]){
                streak++;
            }else{
                streak = 1;
                front = arr[j];
            }

            if(streak == k) return front;
        }

        return *it;
    }
};
