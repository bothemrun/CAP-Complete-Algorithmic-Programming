/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//m0
//each depth/level to top 2 multiset

//O(n)
//but very slow in 1730ms, 9%.

#define max_n ((int)1e5)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    //unordered_map<int,int> val2d, val2h;
    vector<int> val2d, val2h;
    unordered_map<int, multiset<int> > d2h;

    inline void insert(const int& depth, const int& height){
        d2h[depth].insert(height);
        
        if(d2h[depth].size() > 2){
            d2h[depth].erase( d2h[depth].begin() );
        }
    }

    int dfs_hd(TreeNode* node, int depth=0){
        if(node==nullptr) return 0;

        int height = max(
            dfs_hd(node->left, depth+1),
            dfs_hd(node->right, depth+1)
        );

        val2d[node->val] = depth;
        val2h[node->val] = height;
        insert(depth, height);

        return height+1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        val2d.resize(max_n + 1);
        val2h.resize(max_n + 1);

        dfs_hd(root);

        int root_height = val2h[root->val];

        int qn = queries.size();
        vector<int> ans(qn);
        for(int qi=0;qi<qn;qi++){
            const int& val = queries[qi];

            int height = root_height;
            const int& depth = val2d[val];
            const int& sub_height = val2h[val];

            if(depth + sub_height == root_height){
                if(d2h[depth].size() <= 1){
                    height = depth - 1;
                }else{
                    height = depth + *d2h[depth].begin();
                }
            }

            ans[qi] = height;
        }
        return ans;
    }
};
