#define ALPHABET (200+1)
#include<unordered_map>
class TrieNode{
public:
    //class TrieNode* children[ALPHABET] = {};
    unordered_map<int, class TrieNode*> children;
    bool end = false;
};
class Trie{
public:
    class TrieNode* root;
    vector<int>* nums_ptr;
    Trie(vector<int>* nums_ptr){
        root = new TrieNode();
        this->nums_ptr = nums_ptr;
    }

    inline void insert(const int& low, const int& high){
        class TrieNode* node = root;
        for(int i=low;i<=high;i++){
            int num = nums_ptr->at(i);
            //if(node->children[num] == nullptr)
            if(node->children.count(num) == 0)
                node->children[num] = new TrieNode();
            node = node->children[num];
        }
        node->end = true;
    }

    //void dfs(int& cnt, const int& k, const int& p, class TrieNode* node, int divisible_cnt=0){
    void dfs(int& cnt, const int& k, const vector<bool>& divisible, class TrieNode* node, int divisible_cnt=0){
        if(divisible_cnt > k)return;
        if(node->end) cnt++;

        //for(int i=1;i<ALPHABET;i++)if(node->children[i]){
        for(const auto& [i, child]: node->children){
            //dfs(cnt, k, p, node->children[i], divisible_cnt + ( (i%p==0)? 1:0 ) );
            //dfs(cnt, k, divisible, node->children[i], divisible_cnt + divisible[i] );
            dfs(cnt, k, divisible, child, divisible_cnt + divisible[i] );
        }
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        class Trie* tr = new Trie(&nums);
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                tr->insert(i, j);

        //NOTE: optim: mod is costly, so preprocessing
        vector<bool> divisible(ALPHABET, false);
        for(const int& num: nums)if(num%p == 0) divisible[num] = true;

        int cnt = 0;
        tr->dfs(cnt, k, divisible, tr->root);
        return cnt;
    }
};
