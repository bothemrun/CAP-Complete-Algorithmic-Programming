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

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for(int i=1;i<n;i++){
            int res = knows(candidate, i);
            if(res == false) continue;
            else candidate = i;
        }

        for(int i=0;i<n;i++)if(i != candidate){
            if( !knows(i, candidate) || knows(candidate, i) ) return (-1);
        }

        return candidate;
    }
};
