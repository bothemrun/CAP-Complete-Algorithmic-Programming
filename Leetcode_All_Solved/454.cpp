#include<unordered_map>
#include<utility>
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        //hash map: nums1[] + nums2[] --> times
        unordered_map<int,int> sum12times;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                unordered_map<int,int>::iterator f = sum12times.find(nums1[i]+nums2[j]);
                if(f == sum12times.end()){
                    pair<int,int> p (nums1[i]+nums2[j], 1);
                    sum12times.insert(p);
                }else f->second++;
            }
        //
        int ans = 0;
        for(int k=0;k<n;k++)
            for(int l=0;l<n;l++){
                unordered_map<int,int>::iterator f = sum12times.find(0-nums3[k]-nums4[l]);
                if(f != sum12times.end()) ans += f->second;
            }
        return ans;
    }
};
