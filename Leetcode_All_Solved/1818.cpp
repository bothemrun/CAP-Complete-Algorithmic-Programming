//m0
//O(nlogn) binary search
#define mod ((long long)1e9 + 7LL)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        long long ori = 0;
        for(int i=0;i<n;i++)
            ori = ori + (long long)abs(nums1[i] - nums2[i]);


        vector<int> arr(n);
        for(int i=0;i<n;i++) arr[i] = nums1[i];
        sort(arr.begin(), arr.end());

        long long ans = ori;
        for(int i=0;i<n;i++){
            //the the donw part, if arr[j] == nums2[j], 
            //then j-1 doesn't matter, 'cuz it's already covered by the up part.
            int j = lower_bound(arr.begin(), arr.end(), nums2[i]) - arr.begin();

            const long long diff0 = abs(nums1[i] - nums2[i]);
            if(j<n) ans = min(ans, ori - diff0 + abs(arr[j] - nums2[i]) );
            if(j-1>=0) ans = min(ans, ori - diff0 + abs(arr[j-1] - nums2[i]) );
        }

        return ans%mod;
    }
};
