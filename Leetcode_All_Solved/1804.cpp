//m0
//use subtree count and destructor with the parent for the subtree.
#define test 0 //1
#define ALPHABET 26
#include<assert.h>
class TrieNode{
public:
    vector<class TrieNode*> children;
    int word_end;
    int subtree_cnt;

    TrieNode(){
        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++) children[i] = nullptr;
        word_end = 0;
        subtree_cnt = 0;
    }

    //NOTE: destructor for a subtree
    ~TrieNode(){
        for(class TrieNode* tn: children)if(tn != nullptr)
            delete tn;
    }
};

class Trie {
public:
    class TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                node->children[ci] = new TrieNode();
            node = node->children[ci];

            node->subtree_cnt++;
        }
        node->word_end++;
    }

    inline class TrieNode* search(const string& word){
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                return nullptr;
            node = node->children[ci];
        }
        return node;//also for prefix
    }
    
    int countWordsEqualTo(string word) {
        class TrieNode* node = search(word);
        if(node == nullptr)return 0;
        return node->word_end;
    }
    
    int countWordsStartingWith(string prefix) {
        class TrieNode* node = search(prefix);
        if(node == nullptr)return 0;
        return node->subtree_cnt;
    }
    
    void erase(string word) {
        #if test == 1
        class TrieNode* tmp = search(word);
        assert(tmp != nullptr && tmp->word_end > 0);
        #endif
        
        class TrieNode* parent = nullptr;
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            #if test == 1
            assert(node->children[ci] != nullptr);
            #endif

            parent = node;
            node = node->children[ci];

            if( --node->subtree_cnt == 0 ){
                delete node;
                parent->children[ci] = nullptr;
                return;
            }
        }

        node->word_end--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
