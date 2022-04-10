#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<long long> prefix_sum = {0};//NOTE
        unordered_map<long long, vector<int>> prefix_sum2idxes;//NOTE
        for(int i=0;i<nums.size();i++){
            long long p = prefix_sum.back() + nums[i];
            prefix_sum.push_back(p);
            if(prefix_sum2idxes.count(p)) prefix_sum2idxes[p].push_back(i);
            else prefix_sum2idxes[p] = vector<int>({i});
        }
        
        int ans = 0;
        for(int low=0;low<prefix_sum.size();low++){
            //low idx < high idx. low idx can = empty sum. (so high idx != empty sum)
            unordered_map<long long, vector<int>>::iterator f = prefix_sum2idxes.find( k + prefix_sum[low] );
            if(f == prefix_sum2idxes.end())continue;
            
            int nums_idx = low - 1;//NOTE: for the empty sum at 0
            for(const int& idx:f->second)if(idx > nums_idx)ans++;//NOTE
        }
        return ans;
    }
};
