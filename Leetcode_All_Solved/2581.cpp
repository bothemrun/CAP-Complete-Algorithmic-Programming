//2858. Minimum Edge Reversals So Every Node Is Reachable hard

//rerooting, dp on trees. rerooting by filling dp[child]
//O(n)

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
    vector<vector<int>> al;
    vector<unordered_set<int>> rev_e;

    vector<int> rev_cnt;

    int postorder_rev_cnt(const int& node, const int& par=(-1)){
        int cnt = 0;
        for(const int& child: al[node])if(child != par){
            cnt += postorder_rev_cnt(child, node);

            if(rev_e[node].count(child) != 0){
                cnt++;
            }
        }

        return cnt;
    }

    void preorder_rerooting_rev_cnt(const int& node, const int& par=(-1)){
        for(const int& child: al[node])if(child != par){
            rev_cnt[child] = rev_cnt[node];

            //ok for all cases including:
            //edge: guesses have u->v v->u
            if(rev_e[node].count(child) != 0){
                rev_cnt[child]--;
            }
            
            if(rev_e[child].count(node) != 0){
                rev_cnt[child]++;
            }

            preorder_rerooting_rev_cnt(child, node);
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        rev_e.resize(n);
        for(const vector<int>& e: guesses){
            rev_e[e[1]].insert(e[0]);
            //child to parent: reversed edge
        }

        //a.
        rev_cnt.resize(n);
        const int any_root = 0;
        rev_cnt[any_root] = postorder_rev_cnt(any_root);

        //b.
        preorder_rerooting_rev_cnt(any_root);

        //c.
        int ans = 0;
        int guess_cnt = guesses.size();
        for(const int& wrong_cnt: rev_cnt)if( guess_cnt - wrong_cnt >= k ){
            ans++;
        }
        return ans;
    }
};
