//NOTE: O(nlogn)
//Greedy proof:

//we sort points according to their ends
//and we do the following steps from left to right (from points with smaller ends to points with larger ends)

//Without loss of generality, assume a[1] < b[1]
//then b's start has 3 options:
//(1) a.end < b.start
//(2) a.start < b.start <= b.end
//(3) b.end <= a.start

//since points on a's right have been shot, so we must shoot a
//and in all the 3 cases, it's optimal to shoot at a's end.
//(1 get shot for case (1), and 2 balloons get shot for case (2) & (3) .)

#include<algorithm>
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp_fn);
        int shot = 0;
        int i = 0;
        while(i < points.size()){
            shot++;

            int end = points[i][1];
            while(i < points.size() && points[i][0] <= end){
                //NOTE: include self
                i++;
            }
        }

        return shot;
    }
};
