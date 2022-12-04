#include<limits.h>
#include<algorithm>
class Solution {
public:
    int set_find(const int& a, vector<int>& s){
        if(s[a] == (-1))return a;
        return (s[a] = set_find(s[a], s));
    }
    void set_join(int a, int b, vector<int>& s){
        a = set_find(a, s);
        b = set_find(b, s);
        if(a != b){//NOTE: 1 at root
            if(a < b) s[b] = a;
            else s[a] = b;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> s(n+1, (-1));
        for(const vector<int>& road: roads)
            set_join(road[0], road[1], s);
        
        int min_score = INT_MAX;
        for(const vector<int>& road: roads){
            if(set_find(road[0], s) == 1 || set_find(road[1], s) == 1)
                min_score = min(min_score, road[2]);
        }
        return min_score;
    }
};
