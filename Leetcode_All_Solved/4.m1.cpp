//m1
//divide & conquer in O(logm + logn) = O(log(m * n))
//still not in O(log(m + n))


//[Thinking Process]

//[A] k'th Element Helper
//1. then deal with odd/even (m+n) accordingly.


//[B] Divide Both in 2 Halves, Discard 1 of the 2 Halves
//1. if the 2 halves have 2 & 3 elements, but we the 3rd(1-indexed) element,
//2. and A_right's min <= B_right's min,
//3. then discard B_right.
//4. so we can have log(m) + log(n) complexity.

//[C] How To Divide? Like Binary Search?
//1. divide into [low, mid] [mid+1, high], then:
//2. to discard 1 of the left half, compare A[mid1] & B[mid2]
//3. to discard 1 of the right half, compare A[mid1 + 1] & B[mid2 + 1]
//4. finally if len(A) == 0, then return B[...]

//[D] Problem of [C]
//1. counterexample: Example 1: [1, 3], [2] --> infinite loop.
//2. 'cuz mid+1 is null.

//[E] New Divide: A[mid1] & B[mid2] in Different Parts
//1. let [low, mid] has len elements.
//2. cut between [..., len1+len2+1] & [len1+len2+2, ...] elements.
//3. and most importantly, don't have worry the null problem in [D].
//4. and we can compare A[mid1] & B[mid2] only, no A[mid1 + 1] as in [C]

//[F] Base Case/ Edge Case
//1. finally if len(A) == 0, return B[...]

#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;

    int kth_divide_conquer(const vector<int>& A, const vector<int>& B, int low1, int high1, int low2, int high2, int k){
        //k is 1-indexed
        assert(k >= 1);
        if(!(low1 <= high1)){
            assert(low2 + (k-1) < n);
            return B[low2 + (k-1)];
        }
        if(!(low2 <= high2)){
            assert(low1 + (k-1) < m);
            return A[low1 + (k-1)];
        }

        int mid1 = low1 + (high1-low1)/2;
        int mid2 = low2 + (high2-low2)/2;
        int len1 = mid1 - (low1-1);
        int len2 = mid2 - (low2-1);
        int mid1_or_mid2_len = (len1-1) + (len2-1) + 1;

        int val1 = A[mid1];
        int val2 = B[mid2];

        if(k <= mid1_or_mid2_len){
            //answer in the left
            //discard 1 of right [mid+1, high]
            if(val1 < val2)//2's right [mid2, high2]
                return kth_divide_conquer(A, B, low1, high1, low2, mid2 - 1, k);
            else//1's right [mid1, high1]
                return kth_divide_conquer(A, B, low1, mid1 - 1, low2, high2, k);
        }else{
            //answer in the right
            //discard 1 of left [low, mid]
            if(val1 < val2){
                //1's left [low1, mid1]
                int left_len1 = mid1 - (low1-1);
                return kth_divide_conquer(A, B, mid1 + 1, high1, low2, high2, k - left_len1);
            }else{
                //2's left [low2, mid2]
                int left_len2 = mid2 - (low2-1);
                return kth_divide_conquer(A, B, low1, high1, mid2 + 1, high2, k - left_len2);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        if((m+n)%2 == 1){
            //1-indexed
            int k = (m+n)/2 + 1;
            assert(k <= m+n);

            return kth_divide_conquer(nums1, nums2, 0, m-1, 0, n-1, k);
        }else{
            //1-indexed
            int k_left = (m+n)/2;
            int k_right = k_left + 1;
            assert(k_right <= m+n);

            return (
                kth_divide_conquer(nums1, nums2, 0, m-1, 0, n-1, k_left) +
                kth_divide_conquer(nums1, nums2, 0, m-1, 0, n-1, k_right)
            )/2.0;
        }
    }
};
