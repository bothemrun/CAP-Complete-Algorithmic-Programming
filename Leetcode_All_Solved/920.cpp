//m0

//recursion with memo.
//consider the last song added: 2 choices:
//(1) it's an old song.
//(2) it's a new song.
//memo[number of played songs with duplicates][number of played unique songs]

//https://leetcode.com/problems/number-of-music-playlists/solutions/180338/dp-solution-that-is-easy-to-understand/

#define mod ((long long)1e9 + 7)
#define notyet (-1)
#include<algorithm>

class Solution {
public:
    vector<vector<long long>> memo;
    int k;
    int total_unique;

    long long enum_last_add_new_or_old(const int& total_with_dup, const int& unique_cnt){

        if(total_with_dup < unique_cnt) return 0;
        if(total_with_dup == 0 && unique_cnt == 0) return 1;
        if(unique_cnt == 0) return 0;

        if(memo[total_with_dup][unique_cnt] != notyet) return memo[total_with_dup][unique_cnt];

        //(choice 1): add new song
        long long add_new = (
            enum_last_add_new_or_old(total_with_dup - 1, unique_cnt - 1) * 
            (long long)(total_unique - (unique_cnt - 1) )
        )%mod;

        //(choice 2): add old song
        //NOTE: but under the constraint of k other unique song window.
        //NOTE: goes from memo[total - 1][unique] * unique to memo[total - 1][unique] * (unique - k)
        //NOTE: the last k songs must be unique, so total == unique in that window.
        long long add_old = (
            enum_last_add_new_or_old(total_with_dup - 1, unique_cnt ) *
            (long long)max( ( unique_cnt - k ), 0 )
        )%mod;

        return memo[total_with_dup][unique_cnt] = (add_new + add_old)%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        //1-indexed for count
        memo.resize(goal + 1, vector<long long>(n + 1, notyet));

        this->k = k;
        this->total_unique = n;

        return enum_last_add_new_or_old(goal, n);
    }
};
