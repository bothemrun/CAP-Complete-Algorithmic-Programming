//m0

//[A] brute force: choose or skip subset O(3^n) = 3e9

//[B] vanilla knapsack dp(i, left sum, right sum) = O(n * (sum/2)^2) = O(20*5000^2) = 5e8

//[C]
//1. in [B], we want to find max k s.t. dp(n-1, k, k) == true.
//2. it doesn't matter if it's (2, 2) or (100+2, 100+2)
//3. the only matters is their diff.

//4. dp(i, diff)


//[D] recover param from val / use memo value as memo param:

//1. dp(i, diff) = left.  (diff == left - right)

//2. from dp(i, left, right) = bool, to dp(i, diff) = left

//3. kind of like: "MLE/TLE? Drop One Parameter, Recover It from Others" from Chapter "More Advanced Topics" in Halim Competitive Programming 3.


//[E] why can't dp(i, left) = diff.  (diff == left - right)?

//1. more intuitive from dp(i, left, right).

//2. 3 choices in dp recursion (skip, choose left/right).

//3. for dp(i, diff) = left, we use max of 3.

//4. here, we have remember all different diff values, 'cuz we can't max(3 diff).


//O(n * (max_sum) ) = O(20 * 5000) = 1e5

#define max_sum 5000
#define max_1sum (max_sum/2)
#define offset (max_1sum)
#define memo_size (max_sum + 4)

#define inf_add(a,b) ( (a==INT_MIN || b==INT_MIN)? INT_MIN:(a+b) )

class Solution {
public:
    int n;
    const int notyet = (-1);
    const int impossible = INT_MIN;
    vector<vector<int>> memo;

    int knapsack_val_as_param(const vector<int>& rods, int i, int diff){
        //if(i==n) return 0;
        if(i==n) return (diff==0)? 0:impossible;

        //pruning
        if(abs(diff) > max_1sum) return impossible;

        if(memo[i][diff + offset] != notyet)
            return memo[i][diff + offset];

        //3 choices
        //be careful it's current or previous left / diff.
        //but can infer from the definition: diff := left - right, and see the change in diff.
        return memo[i][diff + offset] = max({
            knapsack_val_as_param(rods, i+1, diff), //skip
            inf_add(
                rods[i],
                knapsack_val_as_param(rods, i+1, diff + rods[i] )
            ), //choose left
            knapsack_val_as_param(rods, i+1, diff - rods[i] ) //choose right
        });
    }

    int tallestBillboard(vector<int>& rods) {
        this->n = rods.size();
        memo.resize(n, vector<int>(memo_size, notyet));

        int ans = knapsack_val_as_param(rods, 0, 0);
        return (ans==impossible)? 0:ans;
    }
};
