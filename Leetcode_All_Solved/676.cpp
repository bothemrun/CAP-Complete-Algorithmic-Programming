#define ALPHABET 26
class TrieNode{
public:
    vector<class TrieNode*> children;
    bool word_end;
    TrieNode(){
        word_end = false;
        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++)children[i] = nullptr;
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
    inline void insert(const string& word){
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                node->children[ci] = new TrieNode();
            node = node->children[ci];
        }
        node->word_end = true;
    }
    bool search_wildcard_dfs(const string& word, const int& change=0, class TrieNode* node=nullptr, int i=0){
        if(!node) node = root;
        for(;i<word.size();i++){
            int ci = word[i] - 'a';
            
            if(change == 0){
                for(int cj=0;cj<ALPHABET;cj++)if(cj != ci && node->children[cj]){
                    if(search_wildcard_dfs(word, change+1, node->children[cj], i+1))
                        return true;
                }
            }

            if(node->children[ci] == nullptr)return false;
            node = node->children[ci];
        }

        return node->word_end && change == 1;
    }
};

class MagicDictionary {
public:
    class Trie* tr;
    MagicDictionary() {
        tr = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(const string& word: dictionary)
            tr->insert(word);
    }
    
    bool search(string searchWord) {
        return tr->search_wildcard_dfs(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
