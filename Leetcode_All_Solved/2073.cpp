#include<assert.h>
#include<queue>
#include<utility>
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            q.push(pair<int,int>(i, tickets[i]));
        
        int time = 1;
        while(true){
            q.front().second--;
            if( q.front().first == k && q.front().second == 0) return time;
            if(q.front().second != 0) q.push(q.front());
            q.pop();

            time++;
        }
        assert(false);
        return (-1);
    }
};
