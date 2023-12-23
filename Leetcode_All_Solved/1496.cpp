#define delim "$"
#define hash(a, b) to_string(a) + delim + to_string(b)

#include<unordered_map>
#include<unordered_set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, int> dx;
        unordered_map<char, int> dy;
        dx['N'] = 0;
        dx['S'] = 0;
        dx['E'] = 1;
        dx['W'] = (-1);

        dy['N'] = 1;
        dy['S'] = (-1);
        dy['E'] = 0;
        dy['W'] = 0;

        unordered_set<string> visited;

        visited.insert(hash(0, 0));
        int x=0, y=0;
        for(const char& p: path){
            x += dx[p];
            y += dy[p];
            if(visited.count( hash(x, y) ) != 0) return true;

            visited.insert(hash(x, y));
        }

        return false;
    }
};
