//NOTE: sweep line with priority queue, so don't have to go through the whole line.
//let n = intervals.length, O(nlogn)
//log(10^4) = 4log10 < 4*4, so O(16*10^4) is better than O(10^6)
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
        //for the same meeting, start < end
        if(a.pos != b.pos)return a.pos > b.pos;//min heap for position
        else return a.delta > b.delta;//NOTE: min heap for delta
        //NOTE: for consecutive meetings, previous meeting end is processed before next meeting start
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        priority_queue<class sweep, vector<class sweep>, cmp_class> min_heap;
        for(const vector<int>& i: intervals){
            min_heap.push( sweep(i[0], 1) );
            min_heap.push( sweep(i[1], (-1)) );
        }

        int cur_meeting = 0;
        while(min_heap.size() != 0){
            class sweep s = min_heap.top();
            min_heap.pop();

            cur_meeting += s.delta;

            if(cur_meeting >= 2)return false;
        }
        return true;
    }
};
