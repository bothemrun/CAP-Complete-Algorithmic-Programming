//m0

//Thinking Process:

//[A] Why Not Greedy Depth Topological Sort?
//1. in short, think about a graph with a long chain and a fat column

//[B] 1 Long Chain & 1 Fat Column
//1. think a long (horizontal) chain connected to a node A.
//2. and a fat parallel (vertical) column connected to a node B.
//3. node A & B all connect to a final node.

//[C] Exactly Compute the Runtime With k=2
//1. the long chain has L nodes
//2. the fat column has (kf) = 2f nodes

//[D] Greedy Depth First Or Fat First?
//1. greedy depth first = max( L, (kf)/(k-1) ) = max(L, 2f)
//2. fat first = (kf)/k + L = f + L

//[E] Summary:
//1. we can make D.1 > D.2 if f > L
//2. we can make D.1 < D.2 if L > 2f


//[F] Finally: NP
//1. so to solve NP with brute force, use bitmask DP.

//[G] Implement:
//1. since naive submask enumeration in O(4^n) = O(4^15) = O(1e9).
//2. submask enumeration in O(3^n) by:
//3. Bit Manipulation: https://cp-algorithms.com/algebra/all-submasks.html
//4. Backtracking: https://codeforces.com/blog/entry/45930
//5. memory in 4:  For n=15, 2^15 x 4 Bytes = 3e4 x 4 Bytes = 1e5 Bytes = 1e2 KB



//[H] Other Minor Conditions for mask:
//1. courses already taken := submask
//2. new courses taken = popcount(mask) - popcount(submask) <= k --> use popcount()
//3. prerequisite courses for mask included in submask --> use bit subset.
//4. mask may be impossible to finish. for eg., example 1, mask=1 is impossible

//[I] How To Make The Prerequisite Mask?
//1. first make 1 level prerequisite.
//2. then make all past prerequisite.


//[J] submask enumeeration by backtracking in G.4
//82/82 testcases passed,
//but TLE: Testcases passed, but took too long.

#define submask_enum_algorithm_backtracking 1
#define submask_enum_algorithm_forloop 0

//#define submask_enum_algorithm submask_enum_algorithm_backtracking
#define submask_enum_algorithm submask_enum_algorithm_forloop




#define is_subset(big, small) ( (small & (~big) ) == 0)

#define notyet (-1)
#define impossible INT_MAX

#include<limits.h>
#include<algorithm>
#include<assert.h>

class Solution {
public:
    int n, k;
    vector<int> prerequisite_all;

    vector<int> memo;




#if submask_enum_algorithm == submask_enum_algorithm_backtracking

    //O(3^n) Submask Enumeration
    //by: https://codeforces.com/blog/entry/45930
    //instead of: https://cp-algorithms.com/algebra/all-submasks.html
    void backtrack_submask(vector<int>& all_submask, const int& mask, int cur_submask, const int& bit){
        if(bit == (-1)){
            if(cur_submask != 0) all_submask.push_back(cur_submask);
            return;
        }

        backtrack_submask(all_submask, mask, cur_submask, bit-1);

        if( ( mask & (1<<bit) ) != 0 ){
            cur_submask |= (1<<bit);
            backtrack_submask(all_submask, mask, cur_submask, bit-1);
        }
    }

    int enum_courses(const int& mask){
        if(mask == 0) return 0;

        if(memo[mask] != notyet) return memo[mask];


        vector<int> all_submask;
        backtrack_submask(all_submask, mask, 0, n-1);

        //NOTE: crucial
        all_submask.push_back(0);

        memo[mask] = impossible;

        //NOTE: submask === all courses taken
        //new courses === Difference Set: mask - submask
        for(const int& submask: all_submask)if(submask != mask){

            bool in_course_limit = __builtin_popcount(mask) - __builtin_popcount(submask) <= k;

            bool taken_all_prerequisite = is_subset( submask, prerequisite_all[mask] );


            if(in_course_limit && taken_all_prerequisite){
                int semester = enum_courses(submask);
                if(semester == impossible) continue;

                memo[mask] = min(
                    memo[mask],
                    1 + enum_courses(submask)
                );
            }
        }

        return memo[mask];
    }

#endif //#if submask_enum_algorithm == submask_enum_algorithm_backtracking


    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        this->n = n;
        this->k = k;

        vector<int> prerequisite_1level(n, 0);
        for(const vector<int>& e: relations){
            prerequisite_1level[ e[1]-1 ] |= ( 1 << (e[0]-1) );
        }

        //O(2^n * n)
        prerequisite_all.resize(1<<n, 0);
        for(int mask=0;mask < (1 << n);mask++){

            for(int bit=0;bit<n;bit++)if( ( mask & (1<<bit) ) != 0 ){
                prerequisite_all[mask] |= prerequisite_1level[bit];
            }
        }



        memo.resize(1<<n, notyet);


#if submask_enum_algorithm == submask_enum_algorithm_forloop
        memo[0] = 0;

        for(int mask=1;mask<(1<<n);mask++){

            memo[mask] = impossible;

            for(int submask=mask;submask>=0;submask = ( (submask-1)&mask )){
                if(submask == mask) continue;

                bool in_course_limit = __builtin_popcount(mask) - __builtin_popcount(submask) <= k;

                bool taken_all_prerequisite = is_subset( submask, prerequisite_all[mask] );


                if(in_course_limit && taken_all_prerequisite){
                    int semester = memo[submask];
                    if(semester == impossible) continue;

                    memo[mask] = min(
                        memo[mask],
                        1 + memo[submask]
                    );
                }

                if(submask == 0) break;
            }
        }

        return memo[ (1<<n) - 1 ];
#endif //#if submask_enum_algorithm == submask_enum_algorithm_forloop




#if submask_enum_algorithm == submask_enum_algorithm_backtracking
        //O(3^n) Submask Enumeration
        return enum_courses( (1<<n) - 1 );
#endif //#if submask_enum_algorithm == submask_enum_algorithm_backtracking
    }
};
