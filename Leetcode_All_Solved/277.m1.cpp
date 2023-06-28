//m1
//Optim 1: cache by bitset
//since C++ unordered_map needs custom hasher for a pair.

//Optim 2: pruning.
//I learned it from the fastest submission.
//the last candidate variable satisfied that knows(candidate, i) == false for all i > candidate,
//which is checked in the previous part.



// read editorial solution for the greedy approach in O(n) with <= 3*n API calls.

//greedy proof:
//if a knows b, then a definitely not the celeb, and b may be the candidate.
//if a not knows b, then vice versa.

//so we start from candidate = 0,
//for each person, we ask the relationship between the person and the current candidate.
//note that we sometimes would change the candidate.
//then we find the only 1 possible candidate in O(n)

//the finally, just check if the candidate is the real celeb in O(n).


/* The knows API is defined for you.
      bool knows(int a, int b); */

#define max_n 100
#define test 1 // 1 0
#include<assert.h>

class Solution {
public:
    int findCelebrity(int n) {
        //[a][b] := knows(a, b)
        vector<bitset<max_n>> to_cached(n);
        vector<bitset<max_n>> to(n);

        int candidate = 0;
        for(int i=1;i<n;i++){
            bool k = knows(candidate, i);

            //NOTE: cache optim
            to_cached[candidate][i] = k;
            to[candidate][i] = k;

            if(k) candidate = i;
        }

        //NOTE: optim by pruning
        //the last candidate variable satisfied that knows(candidate, i) == false for all i > candidate,
        //which is checked in the previous part.
        for(int i=0;i<candidate;i++){
            //NOTE: also impossible to have cached knows(candidate, i)
            #if test == 1
            assert( to_cached[candidate][i] == false);
            #endif

            if( knows(candidate, i) == true) return (-1);
        }

        for(int i=0;i<n;i++)if(i != candidate){
            if( knows(i, candidate) == false) return (-1);
        }

        return candidate;
    }
};
