//[Greedy Proof]

//for seats a <= b, students x <= y
//by order, scheme1 = a to x, b to y
//not by order, scheme2 = a to y, b to x

//the order of a & x doesn't matter, 
//since the seats & students are indistinguishable in absolute difference.
//so without loss of generality, assume a <= y, with 2 cases:


//[think in graphics]


//[case b] enclosure, [x, y] contains [a, b]
//1. scheme2 has an extra overlap (in distance moved).


//[case a] no enclosure, a<=x

//1. if [a, b] & [x, y] has an overlap.
//1.1. scheme2 has an extra overlap, while scheme1 has an opening

//2. if [a, b] & [x, y] has no overlap
//2.1. both schemes have an extra overlap, so same distances moved.


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;
        for(int i=0;i<(int)seats.size();i++){
            ans += abs( seats[i] - students[i] );
        }
        return ans;
    }
};
