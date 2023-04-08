#include<unordered_map>
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, vector<int>> num2idx;
        for(int i=0;i<n;i++){
            if(num2idx.count(nums2[i]) == 0){
                num2idx[nums2[i]] = {1, i};
            }else num2idx[nums2[i]].push_back(i);
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = num2idx[ nums1[i] ][ num2idx[ nums1[i] ][0]++ ];
        }
        return ans;
    }
};
