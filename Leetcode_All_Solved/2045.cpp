//m0

//[A] for the same count of visited edges, the time spent is the same.

//1. becomes an unweighted graph.


//[B] the tricky part is the 2nd min time.

//1. allow visit[i] <= 2.
//2. if a new time is updatable (!= 1st min time), then that's the 2nd min time,
//3. the reason is by [A] --> for (time2, level2) (time3, level3) with level2 < level3 --> time2 < time3.
//4. also, if the same level, time is the same.

//5. can also be proved like: A->B1->B2->B3->C must > A->B1->B2->C & A->B1->C


//[C] multi-state bfs

//1. see [B].1. as a multi-state bfs, state = (i, visited frequency)

#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> al(n);
        for(const vector<int>& e: edges){
            al[e[0]-1].push_back(e[1]-1);
            al[e[1]-1].push_back(e[0]-1);
        }

        //multi-state bfs, state = (i, visited frequency)
        queue<tii> q;
        vector<int> ever2q(n, 0);
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));

        q.push(tii(0, 0));
        ever2q[0] = 1;
        dist[0][0] = 0;

        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                const auto [u, u_time] = q.front();
                q.pop();

                //compute new time
                int round = u_time / change;
                //round odd: red light: wait for the end of the red light.
                int new_time = (round%2==0)? (u_time + time):( change * (round+1) + time );

                //(1) if not visited all states (v, freq=1) & (v, freq=2)
                //(2) updatable
                for(const int& v: al[u])if(ever2q[v] <= 1){
                    //consider [[1,2], [2,4],   [1,3], [3,4]]
                    //we don't want to push 2 identical states (4, freq=1).
                    if(ever2q[v] == 0){
                        ever2q[v]++;

                        q.push(tii(v, new_time));
                        dist[v][0] = new_time;
                    }else if(new_time != dist[v][0]){ //NOTE: updatable
                        assert( ever2q[v] == 1 );
                        ever2q[v]++;

                        q.push(tii(v, new_time));
                        dist[v][1] = new_time;

                        if(v==n-1){
                            return dist[v][1];
                        }
                    }
                    /*
                    if(new_time != dist[v][0]){

                    }else if(new_time != dist[v][1]){

                    }*/
                }
            }
        }

        assert(false);
        return (-1);
    }
};
