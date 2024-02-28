//O(nlogn) due to sorting
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int min_diff = arr.back() - arr.front() + 1;
        for(int i=0;i+1<n;i++)
            min_diff = min(min_diff, arr[i+1] - arr[i] );
        
        vector<vector<int>> ans;
        for(int i=0;i+1<n;i++)if( arr[i+1] - arr[i] == min_diff )
            ans.push_back( vector<int>({arr[i], arr[i+1]}) );
        return ans;
    }
};
