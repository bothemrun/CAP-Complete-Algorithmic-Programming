//m0
// m == max of end == 10^6, O(m)
//standard 1D sweep line, w/o priority queue
//NOTE: actually, method 1 w/o traversing the whole line is better.
#define end_max ((int)(1e6))
#include<algorithm>
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> sweep(end_max + 1, 0);
        for(const vector<int>& inter: intervals){
            sweep[inter[0]]++;
            sweep[inter[1]]--;
        }

        int cur_meeting = 0;
        int max_meeting = 0;
        for(int i=0;i<=end_max;i++){
            cur_meeting += sweep[i];

            max_meeting = max(max_meeting, cur_meeting);
            //NOTE: ok with consecutive meetings
        }
        return max_meeting;
    }
};
