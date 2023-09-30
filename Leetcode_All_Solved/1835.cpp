// distributivity: c and (a xor b) == (c and a) xor (c and b)
// like and: mutiplication, xor: addition

// then xor of (a[i] and b[j]) for all j ==
// a[i] and ( xor of all b[j] )

// let ( xor of all b[]j ) := B
//( xor of a[i] and B ) for all i ==
// ( xor of all [i] ) and B

//O(m+n)
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();

        int xor1 = 0;//identify
        for(const int& x: arr1) xor1 ^= x;
        int xor2 = 0;
        for(const int& x: arr2) xor2 ^= x;
        return xor1 & xor2;
    }
};
