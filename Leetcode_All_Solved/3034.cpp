//m0
//brute force. O(nm)

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        int ans = 0;
        for(int i=m;i<n;i++){
            bool match = true;

            for(int j=0;j<m;j++){
                const int& p = pattern[j];

                int diff = nums[ (i-m) + j+1 ] - nums[ (i-m) + j ];
                int sign = 0;
                if(diff > 0) sign = 1;
                else if(diff < 0) sign = (-1);

                if(p != sign){
                    match = false;
                    break;
                }
            }

            ans += match;
        }

        return ans;
    }
};
