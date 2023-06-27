//m1

//two pointer squeeze matrix & triangle, 
//https://leetcode.com/problems/container-with-most-water/solutions/6099/yet-another-way-to-see-what-happens-in-the-o-n-algorithm/

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
    vector<vector<int>> ans;

    inline void two_pointer_squeeze_matrix_triangle(const vector<int>& nums, const int& i, const int& target){
        int low = i+1, high = n-1;

        while(low < high){
            int sum = nums[low] + nums[high];

            if(sum == target){
                ans.push_back( vector<int>( { nums[i], nums[low], nums[high] } ) );

                //NOTE: must de-duplicate before checking if sum == target.
                //NOTE: 'cuz a [2,2] pair with the same values & distinct indices may be valid.
                while(low < high && nums[low] == nums[low+1] )  low++;
                while(low < high && nums[high] == nums[high-1] ) high--;
                //de-duplicate by going to the last of the same value window.

                //go to next
                low++;
                high--;

            }else if(sum < target) low++;
            else high--;
            //NOTE: can't de-duplicate if sum != target
            //NOTE: 'cuz a [2,2] pair with the same values & distinct indices may be valid.
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            two_pointer_squeeze_matrix_triangle(nums, i, 0 - nums[i] );

            //NOTE: must de-duplicate before getting the answer
            //NOTE: edge case: [3,3,3] all same with distinct indices
            while(i+1<n && nums[i] == nums[i+1] ) i++;
            //de-duplicate by going to the last of the same window.
        }

        return ans;
    }
};
