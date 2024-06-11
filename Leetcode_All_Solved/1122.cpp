#include<functional>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        const int max_nums = 1000+1;
        const int absent = (-1);

        vector<int> val2rank2(max_nums, absent);
        for(int i=0;i<(int)arr2.size();i++)
            val2rank2[ arr2[i] ] = i;
        
        function<bool(const int&, const int&)> cmp = [&val2rank2](const int& a, const int& b){
            if(val2rank2[a] != absent && val2rank2[b] != absent)
                return val2rank2[a] < val2rank2[b];
            else if(val2rank2[a] == absent && val2rank2[b] == absent)
                return a<b;
            else if(val2rank2[a] != absent && val2rank2[b] == absent)
                return true;
            else
                return false;
        };

        sort(arr1.begin(), arr1.end(), cmp);

        return arr1;
    }
};
