//NOTE:(1) child.ans = root.ans - child.cnt + (total_cnt - child.cnt) --> postorder
//(1) but preorder not work, 'cuz don't know the up and down sum of a node's upper part.
//(2) but what's the topmost root? for acyclic graph, any node is.
//(3) but undirected, how to know parent-child relation?
//(3) use visited vector, or use order(..., parent)
class Solution {
public:
    vector<vector<int>> adjlist;
    const int topmost_root = 0;
    int total_cnt;

    vector<int> cnt;
    vector<int> sum;

    void cnt_sumtopmost_postorder(const int& root, const int& parent){
        int children_cnt = 0;
        for(const int& child: adjlist[root])if(child != parent){
            cnt_sumtopmost_postorder(child, root);

            children_cnt += cnt[child];
        }

        sum[topmost_root] += children_cnt;

        //ok for no children
        cnt[root] = children_cnt + 1;
    }

    void sum_preorder(const int& root, const int& parent){
        for(const int& child: adjlist[root])if(child != parent){
            sum[child] = sum[root] - cnt[child] + (total_cnt - cnt[child]);

            sum_preorder(child, root);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        total_cnt = n;
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& e: edges){
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }

        cnt = vector<int>(n, 0);
        sum = vector<int>(n, 0);

        cnt_sumtopmost_postorder(topmost_root, (-1));

        sum_preorder(topmost_root, (-1));

        return sum;
    }
};


