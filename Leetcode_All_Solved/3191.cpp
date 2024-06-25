//995. Minimum Number of K Consecutive Bit Flips hard

//for the leftmost 0 bit, no's gonna help it. it must help itself. --> greedy

//use a difference array to track flips.
//O(n)

#define flip_len 3

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int flip = 0;

        vector<int> diff(n+1, 0);
        int sweep = 0; //no overflow

        int i;
        for(i=0;i+(flip_len-1)<n;i++){
            sweep += diff[i];

            if( ( nums[i] ^ (sweep%2) ) == 0){
                flip++;

                sweep++;
                diff[i+(flip_len-1) + 1]--;
            }
        }

        for(;i<n;i++){
            sweep += diff[i];

            if( ( nums[i] ^ (sweep%2) ) == 0)
                return (-1);
        }
        return flip;
    }
};
