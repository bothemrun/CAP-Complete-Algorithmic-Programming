//m0
//use extra cost to merge subtree child set.
//but still O(n^2)

//TODO: 2479 Maximum XOR of Two Non-Overlapping Subtrees to enumerate 2 non-overlapping subtres.

//utilized xor: multiplication equals division.

#include<unordered_set>
#include<limits.h>

class Solution {
public:
    int n;
    vector<vector<int>> al;

    vector<int>* nums_p;

    vector<int> subtree_xor;
    vector<unordered_set<int>> subtree_children;

    void dfs_subtree(const int& root, const int& parent){
        subtree_xor[root] = nums_p->at(root);
        subtree_children[root] = unordered_set<int>({root});
        
        for(const int& child: al[root])if(child != parent){
            dfs_subtree(child, root);

            subtree_xor[root] ^= subtree_xor[child];
            //NOTE: extra O(n) cost, but still O(n^2)
            subtree_children[root].insert( subtree_children[child].begin(), subtree_children[child].end() );
        }
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        nums_p = &nums;

        //1. build graph
        n = nums.size();
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        //2. subtree sum(xor), subtree child set
        subtree_xor.resize(n);
        subtree_children.resize(n);
        dfs_subtree(0, (-1));
        

        
        //3. O(n^2) enumerate all 2 subtrees
        int min_score = INT_MAX;
        //NOTE: can't take the root node i=0, since we need 3 distinct components.
        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++){
                vector<int> xors;

                if( subtree_children[i].count(j) != 0 ){
                    //is subtree
                    xors = { subtree_xor[j], subtree_xor[i] ^ subtree_xor[j], subtree_xor[0] ^ subtree_xor[i] };
                }else if( subtree_children[j].count(i) != 0 ){
                    xors = { subtree_xor[i], subtree_xor[j] ^ subtree_xor[i], subtree_xor[0] ^ subtree_xor[j] };
                }else{
                    //non-overlapping
                    xors = { subtree_xor[i], subtree_xor[j], subtree_xor[0] ^ subtree_xor[i] ^ subtree_xor[j] };
                }

                min_score = min(
                    min_score,
                    *max_element(xors.begin(), xors.end()) -
                    *min_element(xors.begin(), xors.end())
                );
            }
        
        return min_score;
    }
};
