//m1
//greatly improved & clear than m0.


//[A] apply dp prefix on 3176. Find the Maximum Length of a Good Subsequence I m1 & m2 methods.
//O(k*n) wisdompeak DP Basic II.

//[B] top down dp?
//1. no, 'cuz dp memo definition uses values instead of the indices.



//[C] greatly improve the dp definitions in m0:

//1. in m0, there are 2 dp memo definitions.

//2. now only 1 --> dp(i, diff, val) just like a top down dp --> ends at i

//3. but use an auxiliary prefix_max for dp's prefix for all vals (so [diff] still remains).

//4. use a big max(), instead of many lines --> not ambiguous that we use last [i]'s memo or the updated memo.

auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //all base cases init to 0
        vector<unordered_map<int, int>> dp_end(k+1);
        vector<int> prefix_max(k+1, 0);//dp prefix max

        for(const int& val: nums){
            //must diff=k~0, not 0~k,
            //which ensures we use lat [i]'s memo,
            //since we use memo[diff-1]
            for(int diff=k;diff>=0;diff--){
                //1. now we use last [i]'s memo.
                //2. 1 big max() is clear
                dp_end[diff][val] = max({
                    1, //length 1 self,
                    1 + dp_end[diff][val], //same value pair
                    (
                        (diff-1>=0)?
                        (1 + prefix_max[diff-1]):
                        1
                    ) //possibly different or same value pair
                });

                //dp prefix max for all previous vals / i
                prefix_max[diff] = max(
                    prefix_max[diff],
                    dp_end[diff][val]
                );
            }
        }

        return prefix_max[k];
    }
};
