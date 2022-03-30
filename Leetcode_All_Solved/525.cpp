#include<unordered_map>
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //NOTE: prefix sum: 1:+1, 0:-1
        vector<int> prefix_sum;
        int cur_sum = 0;
        for(int x:nums){
            if(x == 1)cur_sum++;
            else cur_sum--;
            prefix_sum.push_back(cur_sum);
        }
        
        //NOTE: list of indices with same prefix sum
        //NOTE: in order s.t. v[0] is the lowest idx
        unordered_map<int,vector<int>> equal_prefix_sum_idx;
        for(int i=0;i<prefix_sum.size();i++){
            if(equal_prefix_sum_idx.find(prefix_sum[i]) == equal_prefix_sum_idx.end())
                equal_prefix_sum_idx[prefix_sum[i]] = vector<int>({i});
            else equal_prefix_sum_idx[prefix_sum[i]].push_back(i);
        }
        
        //NOTE: max idx diff
        int max_idx_diff = 0;
        for(unordered_map<int,vector<int>>::iterator it = equal_prefix_sum_idx.begin();it != equal_prefix_sum_idx.end();it++){
            if(it->first == 0) max_idx_diff = max(max_idx_diff, it->second.back() + 1);
            int low = it->second.at(0);
            max_idx_diff = max(max_idx_diff, it->second.back() - low);
        }
        
        return max_idx_diff;
    }
};
