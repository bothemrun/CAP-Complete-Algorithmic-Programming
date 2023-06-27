//use a tree map for each operation in O(logn)

//although converting timestamps to int may have a better performance for tree map searches,
//we still use string timestamps in tree map for the conciseness.

//what the problem description misses:
//we ignore duplicate (id, timestamp) pairs (some one of the id or timestamp may be duplicates).

//NOTE: to find the upper bound for the end,
//we can't do the same as in lower_bound.
//so we use a char with ascii value > digits & ':'
#define end_upper_bound "z"

#include<unordered_map>
#include<map>
#include<unordered_set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class LogSystem {
public:
    unordered_map<string, int> gran2len = {
        {"Year", 4},
        {"Month", 7},
        {"Day", 10},
        {"Hour", 13},
        {"Minute", 16},
        {"Second", 19}
    };

    map<string, unordered_set<int>> time2id;

    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        time2id[timestamp].insert(id);
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        
        auto start_it = time2id.lower_bound(start.substr( 0, gran2len[granularity] ) );

        auto  end_it = time2id.upper_bound( end.substr( 0, gran2len[granularity] ) + end_upper_bound );

        vector<int> ids;
        for(auto it=start_it;it!=end_it;it++)
            ids.insert( ids.end(), it->second.begin(), it->second.end() );
        return ids;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
