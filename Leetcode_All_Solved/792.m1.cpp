//m1
//NOTE: basically it's trie traversal in parallel.
//this method is more like trie.
//this method is actually keeping track of all parallel trie nodes.

//s is large. O(s.size() + sum of words.size()), keep tracking of multiple suffixes simultaneously
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define alphabet 26
class trienode{
public:
    class trienode* children[alphabet] = {0};
    int word_end = 0;
};
class trie{
public:
    class trienode* root;
    trie(){
        root = new trienode();
    }
    inline void insert(const string& word){
        class trienode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                node->children[ci] = new trienode();
            node = node->children[ci];
        }

        node->word_end++;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        class trie* tr = new trie();
        vector<vector<class trienode*>> parallel_trienode(alphabet);

        for(const string& word: words){
            tr->insert(word);

            //NOTE: trap
            int fronti = word.front() - 'a';
            if(parallel_trienode[fronti].size() == 0)
                parallel_trienode[fronti].push_back(tr->root->children[fronti]);
        }


        int cnt = 0;
        for(const char& c: s){
            vector<class trienode*> repeated_char;
            int ci = c - 'a';
            
            for(class trienode* node: parallel_trienode[ci]){
                cnt += node->word_end;

                //NOTE: update next
                for(int i=0;i<alphabet;i++)if(node->children[i] != nullptr){
                    
                    if(i == ci)
                        repeated_char.push_back(node->children[i]);
                    else parallel_trienode[i].push_back(node->children[i]);
                }
            }

            parallel_trienode[ci].clear();
            parallel_trienode[ci] = repeated_char;
        }

        return cnt;
    }
};
