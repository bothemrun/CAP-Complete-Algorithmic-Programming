//m1


//Thinking Process

//[A] Greedy Availability
//1. big_v / small_v := the array with larger / smaller last element.
//1. put max( nums1[i], nums2[i] ) in big_v

//[B] Naive Count Swaps
//1. if the index i doesn't obey <= their last element respectively, then swap.
//get op.

//[C] Another Swap Ways
//1. besides the naive swap in [B],
//2. swap all the unswapped in [B] --> n - op.

//[D] the "Unaffected" Count

//O(n)
//method m1 improve from m0's O(3n) to O(2n)

#include<algorithm>

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        //[A] Greedy Availability
        int big_back = max(nums1.back(), nums2.back());
        int small_back = min(nums1.back(), nums2.back());
        for(int i=0;i<n;i++){
            int big = max(nums1[i], nums2[i]);
            int small = min(nums1[i], nums2[i]);
            if(!(big <= big_back)) return (-1);
            if(!(small <= small_back)) return (-1);
        }


        //[B] naive swap
        int op = 0;
        int back1 = nums1.back();
        int back2 = nums2.back();

        int unaffected = 0;

        for(int i=0;i<n-1;i++){
            int a = nums1[i];
            int b = nums2[i];

            if(!( a <= back1 && b <= back2 )) op++;
            else if(a <= back2 && b <= back1) unaffected++;
        }

        return min(op, n - op - unaffected);
    }
};
