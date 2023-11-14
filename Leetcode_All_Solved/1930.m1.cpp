//m1

//[A] My Method: O(n), not O(26*n):

//1. how to get rid of the 26 constant in O(26*n)?
//1. bitmask + prefix & suffix hash.
//2. prefix & suffix hash of char count for each i on the way.
//3. if the hash count changes from 0 to 1 or 1 to 0,
//4. then change the corresponding bitmask's bit.
//5. then use bitwise and operation for the prefix & suffix bitmask.
//6. for different positions of the same char as the middle char, 
//7. apply bitwise or operation for their results in (5).
//8. finally use __builtin_popcount() or C++20 popcount() to count the result for the char as the middle char.


//[B] Other Methods in the Solutions: O(26*n):

//1. for each 26 char, between the char's first & last occurrence,
//2. use a hash set for count the number of unique chars in between.
//3. this is O(26*n).

//[C] Compare the 2 methods:
//1. [A]/[B] fixes the middle/side char.
//2. [A] additionally uses bitmask.

#define alphabet 26
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        //pre-compute the alphabet masks
        int alpha_mask[alphabet] = {0};
        int flip_alpha_mask[alphabet] = {0};
        alpha_mask[0] = 1;
        flip_alpha_mask[0] = ~alpha_mask[0];

        for(int i=1;i<alphabet;i++){
            alpha_mask[i] = (alpha_mask[i-1] << 1);
            flip_alpha_mask[i] = ~alpha_mask[i];
        }
            

        //prefix/suffix hash of count, 
        //and their coresponding bitmask.
        int prefix[alphabet] = {0};
        int suffix[alphabet] = {0};
        
        int prefix_mask = 0;
        int suffix_mask = 0;

        for(const char& c: s){
            suffix[ c-'a' ]++;
            suffix_mask |= alpha_mask[ c-'a' ];
        }


        //fix each middle char.
        int mid2sides_mask[alphabet] = {0};
        for(const char& c: s){
            //update the suffix hash
            if(--suffix[ c-'a' ] == 0)
                suffix_mask &= flip_alpha_mask[ c-'a' ];

            //c as the middle, the side palindromic chars in the prefix & suffix sides
            mid2sides_mask[ c-'a' ] |= ( prefix_mask & suffix_mask );

            //update the prefix hash
            if(++prefix[ c-'a' ] == 1)
                prefix_mask |= alpha_mask[ c-'a' ];
        }

        //no overflow, since 26^3 = 1e4
        int ans = 0;
        for(int i=0;i<alphabet;i++)
            ans += __builtin_popcount( mid2sides_mask[i] );
        return ans;
    }
};
