#include<assert.h>
#include<unordered_map>

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outdegree;
        for(const vector<string>& e: paths){
            outdegree[ e[0] ]++;

            //same      
            outdegree[ e[1] ] = outdegree[ e[1] ];
        }

        for(const auto& [city, d]: outdegree)if(d == 0)
            return city;
        
        assert(false);
        return "";
    }
};
