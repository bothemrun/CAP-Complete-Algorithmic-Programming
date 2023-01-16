//m0
//m1: binary search
#include<algorithm>
#include<limits.h>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //NOTE: edge case
        if(intervals.size() == 0){
            return vector<vector<int>>({ vector<int>({newInterval}) });
        }
        if(newInterval[1] < intervals.front()[0]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if(intervals.back()[1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> inter;
        int start, end = INT_MIN;
        bool insert = false;
        bool invert = false;
        for(const vector<int>& i: intervals){
            if(i[1] < newInterval[0] || newInterval[1] < i[0] ){
                if(insert){
                    inter.push_back(vector<int>( {start, end} ));
                    insert = false;

                    invert = true;//NOTE
                }else if(newInterval[1] < i[0] && invert == false){
                    //NOTE: no overlap
                    invert = true;
                    inter.push_back(newInterval);
                }

                inter.push_back(i);
                continue;
            }

            if(insert == false){
                insert = true;
                start = min(i[0], newInterval[0]);
            }

            end = max({end, i[1], newInterval[1]});
        }

        //NOTE:
        if(insert)inter.push_back(vector<int>( {start, end} ));


        return inter;
    }
};
