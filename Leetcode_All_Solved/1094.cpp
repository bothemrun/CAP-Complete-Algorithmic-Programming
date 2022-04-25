#include<algorithm>
#include<queue>
#include<utility>
class cmp_class{
public:
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
        return p1.first > p2.first;//min heap of drop off locations
    }
};
class Solution {
private:
    static bool cmp_ptr(const vector<int>& t1, const vector<int>& t2){
        return t1[1] < t2[1];
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), cmp_ptr);
        int passenger = 0;
        priority_queue< pair<int,int>, vector<pair<int,int>>, cmp_class > min_heap;//drop off locations, w/ numPassengers
        for(const vector<int>& t:trips){
            //pick up
            passenger += t[0];
            min_heap.push( {t[2], t[0]} );
            
            //drop off
            while(min_heap.top().first <= t[1]){
                passenger -= min_heap.top().second;
                min_heap.pop();
            }
            
            //check
            if(passenger > capacity)return false;
        }
        return true;
    }
};
