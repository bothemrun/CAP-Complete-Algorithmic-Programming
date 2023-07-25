//m0
//2 pass: subtree sum, enumerating 2 non-overlapping subtrees' max xor.
//O(n * 45)

#define max_bit 45 //log_2 (1e9 * 5e4 / 2)
//NOTE: can't use 1 << max_bit --> overflow.
#define max_mask (1LL << max_bit)

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class TrieNode{
public:
    class TrieNode* children[2] = {0};
    bool word_end = false;
};
class Trie{
public:
    //NOTE: pitfall: at first, no insertion into the trie before. assertion false.
    bool has_insert = false;

    class TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    inline void insert(const long long& num){
        //NOTE: pitfall: at first, no insertion into the trie before. assertion false.
        has_insert = true;

        class TrieNode* node = root;
        for(long long mask=max_mask;mask>0; (mask >>= 1) ){
            bool bit = (num & mask);

            if(node->children[bit] == nullptr)
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }

        node->word_end = true;
    }

    inline long long search_max_xor(const long long& num){
        //NOTE: pitfall: at first, no insertion into the trie before. assertion false.
        if(this->has_insert == false) return 0;
        
        long long cur_xor = 0;

        class TrieNode* node = root;
        for(long long mask=max_mask;mask>0; (mask >>= 1) ){
            bool bit = (num & mask);

            if(bit == 1){
                //want 0
                if(node->children[0] != nullptr){
                    cur_xor += mask;

                    node = node->children[0];
                }else if(node->children[1] != nullptr){
                    //don't give up, still has chances of adding to cur_xor
                    node = node->children[1];                   
                }else{
                    assert(false);
                }
            }else{
                //want 1
                if(node->children[1] != nullptr){
                    cur_xor += mask;

                    node = node->children[1];
                }else if(node->children[0] != nullptr){
                    //don't give up, still has chances of adding to cur_xor
                    node = node->children[0];
                }else{
                    assert(false);
                }
            }
        }

        return cur_xor;
    }
};

class Solution {
public:
    vector<int>* values_p;
    vector<vector<int>> al;

    vector<long long> subtree_sum;

    long long ans = 0;


    long long dfs_subtree_sum(const int& root, const int& parent){
        subtree_sum[root] = values_p->at(root);
        for(const int& child: al[root])if(child != parent){
            subtree_sum[root] += dfs_subtree_sum(child, root);
        }

        return subtree_sum[root];
    }

    void dfs_nonoverlapping2subtree(const int& root, const int& parent, class Trie* tr){
        //NOTE: pitfall: at first, no insertion into the trie before. assertion false.
        ans = max(
            ans,
            tr->search_max_xor( subtree_sum[root] )
        );

        for(const int& child: al[root])if(child != parent){
            dfs_nonoverlapping2subtree(child, root, tr);
        }

        tr->insert( subtree_sum[root] );
    }

    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        values_p = &values;

        //1. build graph
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        //2. subtree sums
        subtree_sum.resize(n, 0);
        dfs_subtree_sum(0, (-1));

        //3. enumerate 2 non-overlapping subtrees
        class Trie* tr = new Trie();
        dfs_nonoverlapping2subtree(0, (-1), tr);
        return ans;
    }
};
