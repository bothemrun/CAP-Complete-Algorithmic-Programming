//m0
//recursion with memo.  partition dp.

// [why median?]
//for a partition(houses that share 1 mailbox),
//prove the best place for the mail box is the median of the houses of the partition.

// [proof by induction]:


// [Base Case]:
//(1) for 2 house partition, the best place is anywhere between them, since the sum is the same.
//(2) for 1 house partition, obviously.

// [Recursive Case 1]:
//(1) for partition with even (n+2) houses:
//(2) total sum = sum for n houses + sum for 2 house
//(3) since in between them are the best for those 2 sums separately.
//(4) so the total sum can have its min by being in between them.

// [Recursive Case 2]:
//(1) for partition with n+1 odd houses:
//(2) being in between n houses is the best for n houses since n is even
//(3) then add the 1 house at the mailbox, which increases the total sum yb 0.


// [Complexity]
//preprocessing of costs to median takes O(n^3)
//DP takes O(n * k * n), sort takes O(nlogn)
//so totally O(n^3) = O(1e6)


// [Ref]:
//hiepit, great picture
//https://leetcode.com/problems/allocate-mailboxes/solutions/685620/java-c-python-top-down-dp-prove-median-mailbox-o-n-3/

#define notyet (-1)
#include<algorithm>
#include<assert.h>
#include<limits.h>
#include<stdlib.h>

class Solution {
public:
    vector<vector<int>> cost;
    vector<vector<int>> memo;

    int partition_median(const int& i, const int& part){
        //for houses[0, i], make them into part partition
        assert(i>=0);
        if(part == 1) return cost[0][i];
        assert(part >= 2);

        if(memo[i][part] != notyet) return memo[i][part];


        //pruning
        int low = part - 1;
        assert(low-1 >= 0);//so j-1 >= 0

        //enumerate this 1 partition [j, i]
        int min_sum = INT_MAX;
        for(int j=i;j>=low;j--){
            min_sum = min(
                min_sum,
                cost[j][i] + partition_median(j-1, part-1)
            );
        }

        return memo[i][part] = min_sum;
    }

    inline int anywhere_in_between(const vector<int>& houses, const int& low, const int& high){
        //NOTE: we say the best is the median,
        //NOTE: but actually anywhere in between them has the same value.
        //NOTE: so for partition with even houses, just don't have to calculate the floating point average.
        int mid = low + (high-low)/2;
        return houses[mid];
    }

    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();

        sort(houses.begin(), houses.end());


        cost.resize(n, vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++){
                int median = anywhere_in_between(houses, i, j);

                int sum = 0;
                for(int k=i;k<=j;k++)
                    sum += abs( houses[k] - median );
                cost[i][j] = sum;
            }
        
        
        memo.resize(n, vector<int>(k+1, notyet) );
        return partition_median(n-1, k);
    }
};
