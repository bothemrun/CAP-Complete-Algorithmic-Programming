//m0

//[A] dp? -->

//1. dp(i) --> O(n*repeated) up to O(n^2)
//2. why can't define dp(val)? still need O(n*repeated) for each same values to enumerate its own i+1/i-1.

//[B] bfs to handle repeated

//[C] trap: useless loops

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> val2idxes;
        for(int i=0;i<n;i++) val2idxes[ arr[i] ].push_back(i);

        queue<int> q;
        vector<bool> ever2q(n, false);

        q.push(0);
        ever2q[0] = true;

        int level = 0;//0 for the edge case: n==1
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                if(u == n-1) return level;

                if(u+1<n && ever2q[u+1] == false){
                    q.push(u+1);
                    ever2q[u+1] = true;
                }
                if(u-1>=0 && ever2q[u-1] == false){
                    q.push(u-1);
                    ever2q[u-1] = true;
                }

                //trap: even if we won't go into this, still lots of useless loops.
                for(const int& v: val2idxes[ arr[u] ])if(v != u && ever2q[v] == false){
                    q.push(v);
                    ever2q[v] = true;
                }

                //trap: without this, TLE!!
                val2idxes.erase( arr[u] );
            }

            level++;
        }

        assert(false);
        return (-1);
    }
};
