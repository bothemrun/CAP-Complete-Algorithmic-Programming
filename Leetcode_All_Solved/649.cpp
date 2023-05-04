//NOTE: greedy strategy: in each round, the senator bans his opponent senator who is the next closest to exercise rights.
//loop case: "RDDR" --> "RD" --> "R"
#include<queue>
#include<assert.h>
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q[2];
        for(int i=0;i<n;i++)
            q[ senate[i] == 'D' ].push(i);
        
        while(q[0].size() != 0 && q[1].size() != 0){
            if(q[0].front() < q[1].front()){
                q[0].push(n + q[0].front());
            }else{
                q[1].push(n + q[1].front());
            }

            q[0].pop();
            q[1].pop();
        }

        assert( (q[0].size() == 0) ^ (q[1].size() == 0) );
        return (q[0].size() == 0)? "Dire":"Radiant";
    }
};
