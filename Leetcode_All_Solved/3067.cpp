//O(n^2)

#define tii tuple<int,int>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int speed;
    vector<vector<tii>> al;

    int dist2div(int& pair_cnt, const int& root, int node, int par=(-1), int dist=0){
        int div = dist%speed == 0;

        //for root
        vector<int> div4root;
        int sum_div4root = 0;

        for(const auto& [child, w]: al[node])if(child != par){
            int child_div = dist2div(pair_cnt, root, child, node, dist + w);

            div += child_div;

            if(node == root){
                div4root.push_back(child_div);

                sum_div4root += child_div;
            }
        }

        if(node == root){
            for(const int& child_div: div4root){
                sum_div4root -= child_div;

                pair_cnt += child_div * sum_div4root;
            }
        }

        return div;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        this->speed = signalSpeed;

        int n = edges.size() + 1;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back( tii(e[1], e[2]) );
            al[e[1]].push_back( tii(e[0], e[2]) );
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int pair_cnt = 0;
            dist2div(pair_cnt, i, i);

            ans[i] = pair_cnt;
        }

        return ans;
    }
};
