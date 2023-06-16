//https://stackoverflow.com/a/7985152
//https://stackoverflow.com/questions/7984955/what-is-wrong-with-my-for-loops-i-get-warnings-comparison-between-signed-and-u

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lower, upper;

    inline int padding(const vector<int>& nums, const int& i){
        int n = nums.size();
        if(i<0) return lower - 1;
        else if(i>=n) return upper + 1;
        else return nums[i];
    }

    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        this->lower = lower;
        this->upper = upper;

        //NOTE: trap: int i converted to unsigned
        //for(int i=(-1);i<nums.size();i++)
        for(int i=(-1), n=nums.size();i<n;i++)
            if(
                padding(nums, i) !=
                padding(nums, i+1) - 1
            ) ans.push_back(vector<int>({
                padding(nums, i) + 1,
                padding(nums, i+1) - 1
            }) );
        
        return ans;
    }
};
