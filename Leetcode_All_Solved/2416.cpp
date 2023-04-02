//NOTE: just a typical trie problem of subtree count and prefix search.
//NOTE: but TLE if i use vector<class TrieNode*> children, and then setting it to nullptr 1 by 1.
//NOTE: no TLE if i use array with whole inititialization:
// class TrieNode* children[26] = {};
#define ALPHABET 26
class TrieNode{
public:
    //NOTE: TLE: vector<class TrieNode*> children;
    class TrieNode* children[ALPHABET] = {};

    int subtree_cnt;
    TrieNode(){
        subtree_cnt = 0;
        
        /* //NOTE: TLE: 
        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++) children[i] = nullptr;*/
    }
};
class Trie{
public:
    class TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    inline void insert(const string& word){
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                node->children[ci] = new TrieNode();
            node = node->children[ci];

            node->subtree_cnt++;
        }
    }
    inline int search_prefix(const string& word){
        int cnt = 0;
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            //NOTE: a word is a prefix of itself: if(node->children[ci] == nullptr) break;
            node = node->children[ci];

            cnt += node->subtree_cnt;
        }
        return cnt;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        class Trie* tr = new Trie();
        for(const string& word: words) tr->insert(word);

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = tr->search_prefix(words[i]);
        }
        return ans;
    }
};
