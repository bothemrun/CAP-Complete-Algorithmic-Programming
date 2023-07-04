//m0

//NOTE: crucial: the case of length 2 can't be generalized by the recursion case.
//NOTE: extremely helpful if we have many base cases from i>j to length = 1, 2.
//NOTE: so the recursion case must start from length >= 3.
//NOTE: note that the recursion case didn't consider the front removal of length 1 & 2.



//NOTE: finally use this implementation
//https://www.geeksforgeeks.org/minimum-steps-to-delete-a-string-after-repeated-deletion-of-palindrome-substrings/
//'cuz inspiration's implementation is not so understanable.



//NOTE: for [i, j], the back end j must be removed with some partner (= i~j)

//NOTE: so 3 parts: [i, partner-1] [partner] [partner+1, j-1] [j]

//NOTE: so we enumerate back end j's partner
//(we can also enumerate front end i's partner)

//so O(n^3)

//non-typical technique.

#define notyet (-1)
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int enum_frontend_partner(const vector<int>& arr, const int& i, const int& j){
        //NOTE: extremely helpful if we have many base cases from i>j to length = 1, 2.
        if(i > j) return 0;
        if(i == j) return 1;
        if(i + 1 == j) return ( arr[i] == arr[j] )? 1:2;

        if(memo[i][j] != notyet) return memo[i][j];

        
        //NOTE: pitfall: int min_remove = INT_MAX;
        //int min_remove = j - (i-1);
        //NOTE: the recursion case didn't consider the front removal of length 1 & 2.
        int min_remove = min(
            1 + enum_frontend_partner(arr, i+1, j),
            ( ( arr[i]==arr[i+1] )? 1:2 ) + enum_frontend_partner(arr, i+2, j)
        );

        //NOTE: enumerate front end i's partner from length >= 3
        for(int partner=i+2;partner<=j;partner++)if( arr[i] == arr[partner] )
            min_remove = min(
                min_remove,
                enum_frontend_partner(arr, i+1, partner-1) +
                enum_frontend_partner(arr, partner+1, j)
            );
        return memo[i][j] = min_remove;
    }

    int minimumMoves(vector<int>& arr) {
        n = arr.size();

        memo.resize(n, vector<int>(n, notyet));
        return enum_frontend_partner(arr, 0, n-1);
    }
};
