//m0
//O( (n-k)*k )
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i+(k-1)<n;i++){

            bool good = true;
            for(int j=i;j+1<=i+(k-1);j++){
                if(!( nums[j]+1 == nums[j+1] )){
                    good = false;
                    break;
                }
            }

            ans.push_back( (good)? nums[i+(k-1)]:(-1) );
        }
        return ans;
    }
};
