//m0

//[A] optimization --> dp/greedy/binary search the answser

//1. for the leftmost 0 bit, no one is gonna help it except itself.
//2. now we know all the flipping subarrays --> minimization problem solved.


//[B] O(n*k) method

//1. for each i with leftmost 0, flip each k-subarray
//2. finally when i+(k-1) >= k, check last segment


//[C] don't want flipping on the way in O(n*k)

//1. so keep the 1D line sweep / difference array on the way


//[D] how about possibility?

//1. after i + (k-1) >= n --> can't flip anymore
//2. check this last segment

//O(n)

#define tii tuple<int,int>
#include<tuple>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        //size=n+1, for turning off by (-1)
        vector<int> diff(n+1, 0);
        int sweep = 0;

        int i;
        for(i=0;i+(k-1)<n;i++){
            sweep += diff[i];

            if( ( nums[i] ^ (sweep%2) ) == 0){
                ans++;

                diff[i] += 1;
                diff[i+(k-1) + 1] -= 1;

                sweep++;
            }
        }

        for(;i<n;i++){
            sweep += diff[i];

            if( ( nums[i] ^ (sweep%2) ) == 0){
                return (-1);
            }
        }

        return ans;
    }
};
