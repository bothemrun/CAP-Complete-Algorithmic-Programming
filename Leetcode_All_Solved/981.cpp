#include<utility>
#include<algorithm>
class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> key2time_val;
    
    string binary(const vector<pair<int,string>>& time_val, const int& target, int low, int high, const int& high_max){
        int mid = low + (high-low)/2;
        if(mid == high_max && time_val[mid].first <= target)return time_val[high_max].second;
        if(mid != high_max && time_val[mid].first <= target && time_val[mid+1].first > target)return time_val[mid].second;
        //impossible:if(low == high)return "";
        
        if(time_val[mid].first > target) return binary(time_val, target, low, mid, high_max);
        else return binary(time_val, target, mid+1, high, high_max);
    }
public:
    TimeMap() {
        //no
    }
    
    void set(string key, string value, int timestamp) {
        auto it = key2time_val.find(key);
        if(it == key2time_val.end()) key2time_val[key] = vector<pair<int,string>>({{timestamp, value}});
        else it->second.push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = key2time_val.find(key);
        if(it == key2time_val.end())return "";
        if(it->second.at(0).first > timestamp)return "";
        
        //sort(it->second.begin(), it->second.end());//TODO
        return binary(it->second, timestamp, 0, it->second.size()-1, it->second.size()-1);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
