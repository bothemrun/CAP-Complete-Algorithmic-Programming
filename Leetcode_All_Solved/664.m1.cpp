//m1

//for case (2):
//instead of breaking into [i, k] [k+1, j],
//here into [i, k-1] [k, j]
//meaning we insert the s[j] chars into [k, j] and then change the substring

//enumerate 2 cases for the last char s[right]:
//(1) insert at the end by 1 cost
//(2) there's some j such that s[j] == s[right], so s[right] has 0 cost,
//'cuz at s[j], we already print char s[j] from position [j] to position[right].

//inspired by shlykovich:
//https://leetcode.com/problems/strange-printer/solutions/233067/python-recursive-approach-with-memorization/

//recursion with memo. O(n^3)

#define notyet (-1)
#include<algorithm>

class Solution {
public:
    vector<vector<int>> memo;

    int enum_last_char(const string& s, const int& i, const int& j){
        if(i>j) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        //NOTE: enumerate last char, 2 cases:
        int ret = enum_last_char(s, i, j-1) + 1;//case (1):insert by 1 cost

        const char& insert_char_cost0 = s[j];
        for(int k=i;k<j;k++)if(s[k] == insert_char_cost0)
            ret = min(
                ret,
                enum_last_char(s, i, k-1) + //(i, k)
                enum_last_char(s, k, j - 1) //(k+1, j-1)
                + 0 //case (2):for 0 cost !!!
            );
        return memo[i][j] = ret;
    }

    int strangePrinter(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n, notyet));

        return enum_last_char(s, 0, n-1);
    }
};
