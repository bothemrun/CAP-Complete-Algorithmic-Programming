#include<queue>
#include<unordered_map>
#include<unordered_set>
#define DIGIT 4
class Solution {
private:
    inline void char_round(char& c, char offset){
        if(c == '0' && offset == (-1))c = '9';
        else if(c == '9' && offset == 1)c = '0';
        else c += offset;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_set;
        for(const string& d:deadends){
            dead_set.insert(d);
            if(d == "0000")return (-1);//corner case
        }
        
        queue<string> q;
        unordered_map<string,int> d4visited;//also as visited set
        string lock = "0000";
        d4visited[lock] = 0;
        q.push(lock);
        while(q.size() != 0){
            string n = q.front();
            q.pop();
            if(n == target) return d4visited[n];
            
            for(int digit=0;digit<DIGIT;digit++){
                string up = n;
                //up[digit] = (char)((up[digit] + 1)%10);
                char_round(up[digit], (char)1);
                string down = n;
                //down[digit] = (char)(down[digit] - 1 + 10)%10;
                char_round(down[digit], (char)(-1) );
                
                if(dead_set.count(up) == 0 && d4visited.count(up) == 0){
                    q.push(up);
                    d4visited[up] = d4visited[n] + 1;
                }
                if(dead_set.count(down) == 0 && d4visited.count(down) == 0){
                    q.push(down);
                    d4visited[down] = d4visited[n] + 1;
                }
            }
        }
        
        return (-1);//impossible
    }
};
