//m2
//O(n) greedy with proof:

//values can only move forward.
//so the result is nonincreasing.

//if there's a nums[i] that violates the nondecreasing order, then distribute it to maintain the order, and the bound == nums[0] may have to increase if the distribution reaches nums[0].

//the distribution of nums[i] only distributes to elements lower thant the current nums[i].
//so impossible that after distribution of nums[i], nums[0] increases to nums[0] > old nums[i].

//so why can why the answer is max(forward prefix average ceiling) ?
//assume now we have a nonincreasing, and now nums[i].

//(case 1) if nums[i] obeys the nonincreasing order

//(case 2) if nums[i] doesn't obey the order, and the distribution doesn't reach nums[0]

//--> for (case 1 & 2), nums[0] isn't affected, and max of the nonincreasing triangle >= average of the nonincreasing triangle.
//--> so don't have to update.

//(case 3) if nums[i] so large that the distribution reaches nums[0], then update new bound = prefix average ceiling.

// --> but since we don't know or actually do the distribution, we don't know whether the distribution reaches nums[0] or not.
// --> and since in (case 1 & 2), the prefix average ceiling <= current bound, so we can update the bound (and the bound value doesn't change.)

#include<algorithm>
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long prefix_sum = 0;
        long long bound = 0;
        for(int i=0;i<n;i++){
            prefix_sum += nums[i];
            long long size = i+1;

            //bound = max(bound, prefix_sum/size + ( prefix_sum%size==0)? 0:1 );
            //"()?:" operator < "==" "+" "||"
            bound = max(bound, prefix_sum/size + (
                prefix_sum%size==0? 0:1
            ) );
        }
        return (int)bound;
    }
};
