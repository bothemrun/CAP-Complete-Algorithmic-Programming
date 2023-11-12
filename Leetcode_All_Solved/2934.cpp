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

//[D] Another Swap Ways
//1. swap the last elements.
//2. then do [B] & [C] with the modified arrays.

//O(n)

#include<algorithm>
class Solution {
public:
    int n;
    inline int count_swap(const vector<int>& big_v, const vector<int>& small_v){
        
        int big_back = big_v.back();
        int small_back = small_v.back();

        int op = 0;
        for(int i=0;i<n-1;i++){
            int a = big_v[i];
            int b = small_v[i];
            if(!(a <= big_back && b <= small_back)){
                op++;
            }
        }
        
        return min(op, n - op);
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        
        //availability
        int big = max(nums1.back(), nums2.back());
        int small = min(nums1.back(), nums2.back());
        for(int i=0;i<n-1;i++){
            int a = nums1[i];
            int b = nums2[i];
            if(!( big >= max(a, b) )) return (-1);
            if(!( small >= min(a, b) )) return (-1);
        }
        
        //count swaps
        int min_op = count_swap(nums1, nums2);
        swap(nums1.back(), nums2.back());
        min_op = min( min_op, 1 + count_swap(nums1, nums2) );
        return min_op;
    }
};
