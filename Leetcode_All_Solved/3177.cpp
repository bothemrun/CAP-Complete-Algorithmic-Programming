//m0

//[A] apply dp prefix on 3176. Find the Maximum Length of a Good Subsequence I m1 & m2 methods.
//O(k*n)

//[B] top down dp?
//1. no, 'cuz dp memo definition uses values instead of the indices.


//[C] dp prefix

//1. prefix_same_val[i][diff][val] := dp prefix for nums[0, i], with value (not index) & at most diff different pairs (not exactly).

//2. prefix_all[i][diff] := dp prefix for nums[0, i], with at most diff different pairs (not exactly),
//2.a. including some extra same pairs. so the actual different pair may < diff, but just don't care, since it's "at most diff pairs".


//[D] dp optimization:

//1. prefix_same_val in O(n^2 * k) --> so dp memory optimization --> omit [i] in both memos.


//[E] dp update order:

//1. diff=k to 0, not 0 to k,
//1.a. which ensures that dp memo uses last [i]'s dp memo.

//2. prefix_same_val & prefix_all's order is important.
//2.a. we must ensure we use last [i]'s memo.

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        //all base cases init to 0
        vector<unordered_map<int, int>> prefix_same_val(k+1);
        vector<int> prefix_all(k+1, 0);

        for(const int& val: nums){
            //must diff=k~0, not diff=0~k,
            //which ensures we use last [i]'s memo,
            //since we use memo[diff-1]
            for(int diff=k;diff>=0;diff--){
                //1. before 2., which ensures we use last [i]'s memo in 1.

                //1. same value pair
                prefix_same_val[diff][val] = 1 + prefix_same_val[diff][val];

                //2. different pair
                if(diff-1 >= 0)
                    prefix_same_val[diff][val] = max(
                        prefix_same_val[diff][val],
                        1 + prefix_all[diff-1]
                    );
                
                //3. finally update. and 2. must be before 3,
                //which ensures we use last [i]'s memo in 2.
                prefix_all[diff] = max(
                    prefix_all[diff],
                    prefix_same_val[diff][val]
                );
            }
        }
        return prefix_all[k];
    }
};
