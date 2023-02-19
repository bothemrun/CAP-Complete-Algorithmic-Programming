class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> res;
        int i=0, j=0;
        while(i < m && j < n){
            if(nums1[i].front() == nums2[j].front()){
                res.push_back( vector<int>( {nums1[i].front(), nums1[i].back() + nums2[j].back() } ) );
                i++;
                j++;
            }else if(nums1[i].front() < nums2[j].front()){
                res.push_back( nums1[i++] );
            }else{
                res.push_back( nums2[j++] );
            }
        }
        
        while(i < m){
            res.push_back(nums1[i++]);
        }
        while(j < n){
            res.push_back(nums2[j++]);
        }
        
        return res;
    }
};
