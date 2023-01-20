//NOTE: C++ stl has set/map of vectors

//https://www.geeksforgeeks.org/set-of-vectors-in-c-stl-with-examples/

//https://www.geeksforgeeks.org/map-of-vectors-in-c-stl-with-examples/

//while unordered_set of vectors need customized hasher.
//https://www.geeksforgeeks.org/unordered-set-of-vectors-in-c-with-examples/

#include<set>
class Solution {
public:
    inline void insert(vector<vector<int>>& dp_end_i, set<vector<int>>& setv, const vector<int>& v){
        dp_end_i.push_back(v);
        setv.insert(v);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp_end( n, vector<vector<int>>() );

        //NOTE: set of vectors by stl
        set<vector<int>> setv;

        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)if(nums[j] <= nums[i]){
                for(vector<int> v: dp_end[j]){
                    v.push_back(nums[i]);
                    if(setv.count(v) == 0)
                        insert(dp_end[i], setv, v);
                }

                vector<int> v = {nums[j], nums[i]};
                if(setv.count(v) == 0)
                    insert(dp_end[i], setv, v);
            }
        
        vector<vector<int>> ans;
        for(int i=1;i<n;i++)
            for(const vector<int>& v: dp_end[i])
                ans.push_back(v);
        return ans;
    }
};
