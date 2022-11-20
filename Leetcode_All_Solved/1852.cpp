#include<unordered_map>
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int,int> num2cnt;
        for(int i=0;i<k;i++){
            if(num2cnt.count(nums[i]) == 0)
                num2cnt[nums[i]] = 1;
            else num2cnt[nums[i]]++;
        }
        
        vector<int> distinct;
        for(int i=k-1;i<nums.size();i++){
            distinct.push_back( num2cnt.size() );
            
            //update: delete
            if(--( num2cnt[ nums[i-(k-1)] ] ) == 0)
                num2cnt.erase( nums[i-(k-1)] );
            //update: insert
            if(i+1 < nums.size()){
                if(num2cnt.count(nums[i+1]) == 0)
                    num2cnt[nums[i+1]] = 1;
                else num2cnt[nums[i+1]]++;
            }
        }
        return distinct;
    }
};
