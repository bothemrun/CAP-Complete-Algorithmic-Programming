class Solution {
public:
    inline long long trip_cnt(const vector<int>& time, const long long& total_time){
        //if total_time == 0, return 0
        long long cnt = 0;
        for(const int& t: time)if((long long)t <= total_time)
            cnt += total_time / (long long)t;
        return cnt;
    }
    long long binary_total_time(const vector<int>& time, const int& totalTrips, const long long& low, const long long& high){
        long long mid = (high-low)/2 + low;
        long long trip_cnt_mid;
        if(
            trip_cnt(time, mid-1) < totalTrips &&
            totalTrips <= (trip_cnt_mid = trip_cnt(time, mid) )
        ) return mid;

        if( totalTrips > trip_cnt_mid )
            return binary_total_time(time, totalTrips, mid+1, high);
        else return binary_total_time(time, totalTrips, low, mid);
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        return binary_total_time(time, totalTrips, 1, (long long)time.front()*(long long)totalTrips);
        //return binary_total_time(time, totalTrips, 1, time.front()*totalTrips);
    }
};
