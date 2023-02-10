#define ceiling(a,b) ( a/b + ( (a%b==0)? 0:1 ) )
class Solution {
public:
    int postorder_cnt(const vector<vector<int>>& adjlist, const int& seats, const int& topmost_root, long long& cost, const int& root, const int& parent=(-1)){
        int cnt = 1;
        for(const int& child: adjlist[root])if(child != parent){
            cnt += postorder_cnt(adjlist, seats, topmost_root, cost, child, root);
        }

        if(root != topmost_root)
            cost += ceiling(cnt, seats);

        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adjlist(n, vector<int>());
        for(const vector<int>& e: roads){
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }

        long long cost = 0;
        postorder_cnt(adjlist, seats, 0, cost, 0);
        return cost;
    }
};
