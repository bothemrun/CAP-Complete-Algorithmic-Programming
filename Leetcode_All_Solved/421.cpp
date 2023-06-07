//m0
//by trie
#define bit_size 31 //NOTE: 0~30, can't use the the last sign bit

#include<assert.h>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class trienode{
public:
    class trienode* children[2] = {0};
    bool word_end = false;
};
class trie{
public:
    class trienode* root;
    trie(){
        root = new trienode();
    }
    inline void insert(const vector<bool>& bit){
        class trienode* node = root;
        //NOTE: insert from most significant bits
        for(int i=bit_size-1;i>=0;i--){
            if(node->children[ bit[i] ] == nullptr)
                node->children[ bit[i] ] = new trienode();
            node = node->children[ bit[i] ];
        }
        node->word_end = true;
    }

    inline int search_max_xor(const vector<bool>& bit){
        class trienode* node = root;
        int cur_xor = 0;
        //NOTE: xor from most significant bits
        for(int i=bit_size-1;i>=0;i--){
            cur_xor *= 2;

            if(bit[i] == 0){
                //want 1
                if(node->children[1] != nullptr){
                    node = node->children[1];
                    cur_xor++;
                }else{
                    assert(node->children[0] != nullptr);
                    node = node->children[0];
                }
            }else{
                //want 0
                if(node->children[0] != nullptr){
                    node = node->children[0];
                    cur_xor++;
                }else{
                    assert(node->children[1]);
                    node = node->children[1];
                }
            }
        }

        return cur_xor;
    }
};

class Solution {
public:
    inline void to_bits(int num, vector<bool>& bit){
        for(int i=0;i<bit_size;i++){
            bit[i] = num%2;
            num /= 2;
            //NOTE: will have high 0 bits
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        vector<vector<bool>> bits(n, vector<bool>(bit_size));
        for(int i=0;i<n;i++)
            to_bits(nums[i], bits[i]);

        
        class trie* tr = new trie();
        for(const vector<bool>& bit: bits)
            tr->insert(bit);
        
        int max_xor = INT_MIN;
        for(const vector<bool>& bit: bits)
            max_xor = max(
                max_xor, 
                tr->search_max_xor(bit)
            );
        return max_xor;
    }
};
