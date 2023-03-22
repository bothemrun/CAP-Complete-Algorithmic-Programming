#define ALPHABET 26
class TrieNode{
public:
    vector<class TrieNode*> children;
    int val;
    bool word_end;
    TrieNode(){
        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++)children[i] = nullptr;

        word_end = false;
    }
    ~TrieNode(){
        for(class TrieNode* tn: children)if(tn)
            delete tn;
    }
};
class Trie{
public:
    class TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    inline void insert(const string& key, const int& val){
        class TrieNode* node = root;
        for(const char& c: key){
            int ci = c - 'a';
            if(!node->children[ci])
                node->children[ci] = new TrieNode();
            node = node->children[ci];
        }
        node->word_end = true;
        node->val = val;
    }
    inline class TrieNode* search(const string& key){
        class TrieNode* node = root;
        for(const char& c: key){
            int ci = c - 'a';
            if(!node->children[ci])return nullptr;
            node = node->children[ci];
        }
        return node;
    }
    void sum_subtree(class TrieNode* node, int& sum){
        if(!node)return;
        if(node->word_end) sum += node->val;

        for(class TrieNode* child: node->children)if(child)
            sum_subtree(child, sum);
    }
};

class MapSum {
public:
    class Trie* tr;
    MapSum() {
        tr = new Trie();
    }
    
    void insert(string key, int val) {
        tr->insert(key, val);
    }
    
    int sum(string prefix) {
        int sum_val = 0;
        tr->sum_subtree(tr->search(prefix), sum_val);
        return sum_val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
