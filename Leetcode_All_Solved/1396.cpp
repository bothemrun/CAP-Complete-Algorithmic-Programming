#define max_id ((int)1e6 + 1)
#include<unordered_map>
#include<utility>
#include<assert.h>
class UndergroundSystem {
public:
    //id --> (name, time) for check-in
    vector<pair<string,int>> id2name_time;
    //from name --> to name --> sum, cnt
    unordered_map<string, unordered_map<string, pair<long long, long long> > > fromto2sum_cnt;
    
    UndergroundSystem() {
        id2name_time.resize(max_id);
    }
    
    void checkIn(int id, string stationName, int t) {
        id2name_time[id] = pair<string,int>(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        int time = t - id2name_time[id].second;
        const string& from_name = id2name_time[id].first;

        if(fromto2sum_cnt.count(from_name) == 0)
            fromto2sum_cnt[from_name] = unordered_map<string, pair<long long, long long> >( {{
                stationName,
                pair<long long, long long>(time, 1)
            }} );
        else if(fromto2sum_cnt[from_name].count(stationName) == 0)
            fromto2sum_cnt[from_name][stationName] = pair<long long, long long>(time, 1);
        else{
            fromto2sum_cnt[from_name][stationName].first += time;
            fromto2sum_cnt[from_name][stationName].second++;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        assert(fromto2sum_cnt.count(startStation));
        assert(fromto2sum_cnt[startStation].count(endStation));
        
        return (double)fromto2sum_cnt[startStation][endStation].first / (double)fromto2sum_cnt[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
