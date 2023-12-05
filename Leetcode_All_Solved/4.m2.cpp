//m2
//binary search in O(log( min(m, n) ))
//follows the required O(log(m + n))

//my method uses the general k'th helper, instead of the median helper function.




//[Thinking Process]


//[A] k'th Element Helper:

//1. then deal with odd/even (m+n) accordingly.


//[B] Reverse Thinking: The Merged Conditions:

//1. When merged, A / B has x / y elements A[0, x-1] / [0, y-1] in the merged left [0, k-1]
//2. the middle points: A_left := A[x-1], A_right := A[x].
//2.a. A[x-1] from 0-indexed to 1-indexed, which means the left part has x elements.
//3. so A_left <= B_right & B_left <= A_right 'cuz they're merged.



//[C] Dimension Reduction:

//1. by x, we can get y = k - x
//2. so the question becomes: find x.



//[D] Monotone:

//1. as x grows, both conditions in [B] are monotonically increasing / decreasing respectively.
//2. binary search x in [0, m] element counts.
//2.a. since k is legal in [1, m+n], x can be found.
//3. usual binary search left & right: [low, mid] [mid+1, high]



//[E] Binary Base Case:

//1. Cross <= : A_left <= B_right && B_left <= A_right



//[F] Binary Recursive Case 1: y Out of Bounds:

//1. 'cuz k & x are legal as in [D.2.a], y must be in [0, n]
//2. if(y<0):  x too large, search leftwards.
//3. if(n<y):  x too small, search rightwards.


//[G] Binary Recursive Case 2:

//1. besides Base Case in [E],
//2. if(A_left > B_right):  x too large, search leftwards.
//3. else (B_left > A_right):  x too small, search rightwards.



//[H] Edge Case: 
//1. now ensured 0<=x<=m, 0<=y<=n.
//2. turn 1-indexed count to 0-indexed index

//3. if(x==0):
//3.a. it happens when all of A in the merged right.
//3.b. set A_left = A[(x-1)] = INT_MIN,
//3.c. making A_left <= B_right in [E] true.

//4. if(x==m):
//4.a. it happens when all of A in the merged left.
//4.b. set A_right = A[(x-1) + 1] = INT_MAX,
//4.c. making B_left <= A_right in [E] true.

//5. similar for y==0 & y==n



//[I] Flow Overflow:

//1. so the code structure is a standard binary search.
//2. we deal with edge cases later as in [H], not in front of all the codes as in divide & conquer.





//[J] Complexity:

//1. O(log( min(m, n) ))
//2. if m is very large, m >> n:
//2.a. method m1 in O(log(m) + log(n)) still limited to the large O(log(m)).
//2.b. but this method m2 only limited to the small O(log(n))
//3. so binary search A or B with smaller size.



//[K] Reference:

//1. Editorial & Solutions are hard to understand, so Youtube:
//2. https://www.youtube.com/watch?v=q6IEA26hvXc
//1.1. Neetcode Channel
//3. https://www.youtube.com/watch?v=ScCg9v921ns
//2.1. Channel: https://www.youtube.com/@user-wu9sp8qw8n





//[L] Extended Problem: Find k'th From 2 Sorted Arrays in < linear time.
//1. an array "arr" is formed by merging 2 sorted arrays in their order respectively,
//2. but this result arr is not sorted.
//3. also given array "order", order.size() == arr.size()
//4. for each i in range(arr):
//5. find the order[i]'th element in arr[0, i] in < O(N^2)


#include<algorithm>
#include<limits.h>
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
    int kth_binary(const vector<int>& A, const vector<int>& B, int low, int high, const int& k){
        int asize = A.size(), bsize = B.size();
        assert(low <= high);

        //x === mid
        int x = low + (high-low)/2;


        int y = k - x;
        //x too large, leftwards
        if(!(0<=y)) return kth_binary(A, B, low, x, k);
        //x too small, rightwards
        if(!(y<=bsize)) return kth_binary(A, B, x+1, high, k);



        //1-indexed count to 0-indexed index
        assert(0<=x && x<=asize);
        int A_left = (x==0)? INT_MIN:A[(x-1)];
        int A_right = (x==asize)? INT_MAX:A[(x-1) + 1];

        assert(0<=y && y<=bsize);
        int B_left = (y==0)? INT_MIN:B[(y-1)];
        int B_right = (y==bsize)? INT_MAX:B[(y-1) + 1];


        //binary search base case
        if(A_left <= B_right && B_left <= A_right)
            return max(A_left, B_left);
        

        //binary search recursive cases
        if(!(A_left <= B_right)) //x too large, leftwards
            return kth_binary(A, B, low, x, k);
        else //x too small, rightwards
            return kth_binary(A, B, x+1, high, k);
    }

    inline int kth_binary_helper(const vector<int>& A, const vector<int>& B, const int& k){
        if(A.size() <= B.size())
            return kth_binary(A, B, 0, A.size(), k);
        else return kth_binary(B, A, 0, B.size(), k);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int asize = nums1.size();
        int bsize = nums2.size();

        if((asize+bsize)%2 == 1)
            return kth_binary_helper(nums1, nums2, (asize+bsize)/2 + 1 );
        else{
            int k_left = (asize+bsize)/2;
            return (
                kth_binary_helper(nums1, nums2, k_left) +
                kth_binary_helper(nums1, nums2, k_left + 1)
            )/2.0;
        }
    }
};
