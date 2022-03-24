#include<unordered_map>
#include<utility>
#include<algorithm>
#include<assert.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //record number to idx
        unordered_map<int,vector<int>> num2indices;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,vector<int>>::iterator f = num2indices.find(nums.at(i));
            if(f == num2indices.end()){
                vector<int> v; v.push_back(i);
                pair<int,vector<int>> p (nums.at(i), v);
                num2indices.insert(p);
            }else f->second.push_back(i);
        }
        //sort
        sort(nums.begin(), nums.end());
        //recursive assumption
        vector<int> ans;
        int low = 0, high = nums.size()-1;
        while(low < high){
            if(nums.at(low) + nums.at(high) == target){
                if(nums[low] == nums[high]){
                    unordered_map<int,vector<int>>::iterator f = num2indices.find(nums[low]);
                    assert(f != num2indices.end());
                    assert(f->second.size() >= 2);
                    ans.push_back(f->second.at(0));
                    ans.push_back(f->second.at(1));
                    return ans;
                }else{
                    unordered_map<int,vector<int>>::iterator f_low = num2indices.find(nums[low]);
                    unordered_map<int,vector<int>>::iterator f_high = num2indices.find(nums[high]);
                    assert(f_low != num2indices.end());
                    assert(f_high != num2indices.end());
                    ans.push_back(f_low->second.at(0));
                    ans.push_back(f_high->second.at(0));
                    return ans;
                }
            }else if(nums[low] + nums[high] > target) high--;
            else low++; //NOTE: recursive assumption
        }
        return ans;//not here
    }
};
