#include<algorithm>
#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //
        unordered_map<int,vector<int>> num2indices;
        for(int i=0;i<nums.size();i++)num2indices[nums[i]].push_back(i);
        
        //NOTE: 2 pointers
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.size()-1;
        while(low < high){
            if(nums[low]+nums[high] == target){
                if(nums[low] == nums[high])return vector<int>({ num2indices[nums[low]].at(0), num2indices[nums[low]].at(1) });
                else return vector<int>({ num2indices[nums[low]].at(0), num2indices[nums[high]].at(0) });
            }
            
            //NOTE: not need to go backwards [j+1, k2], k2 > k. why? : when was [j0,k2] at before? (1)j0<=j, ok, already covered. (2)j0==j+1, impossible, since (a)never go backwards.
            if(nums[low]+nums[high] < target)low++;
            else high--;
        }
        
        return vector<int>();//not here
    }
};
