//NOTE: let n = intervals.length = 10^4 
// O(nlogn)
#include<algorithm>
#include<queue>
class sweep{
public:
    int pos;
    int delta;
    sweep(const int& a, const int& b){
        pos = a;
        delta = b;
    }
};

class cmp_class{
public:
    bool operator()(const class sweep& a, const class sweep& b){
        //NOTE: start < end, for the same meeting
        //NOTE: but for consecutive meetings:
        if(a.pos != b.pos) return a.pos > b.pos; //min heap, sink down
        else return a.delta > b.delta;//min heap for delta
        //NOTE: the previous meeting end is processed before the next meeting start
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<class sweep, vector<class sweep>, cmp_class> min_heap;

        for(const vector<int>& inter: intervals){
            min_heap.push( sweep(inter[0], 1) );
            min_heap.push( sweep(inter[1], (-1)) );
        }

        int cur_meeting = 0;
        int max_meeting = 0;
        while(min_heap.size() != 0){
            class sweep s = min_heap.top();
            min_heap.pop();

            cur_meeting += s.delta;

            max_meeting = max(max_meeting, cur_meeting);
        }
        return max_meeting;
    }
};



