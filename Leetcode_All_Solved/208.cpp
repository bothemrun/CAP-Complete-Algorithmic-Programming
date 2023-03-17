#define ALPHABET 26
class TrieNode{
public:
    vector<class TrieNode*> children;
    bool word_end;
    TrieNode(){
        word_end = false;
        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++) children[i] = nullptr;
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
            int ch = c - 'a';
            if(node->children[ch] == nullptr)
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }

        node->word_end = true;
    }
    
    bool search(string word) {
        class TrieNode* node = root;
        for(const char& c: word){
            int ch = c - 'a';
            if(node->children[ch] == nullptr)
                return false;

            node = node->children[ch];
        }

        return node->word_end;
    }
    
    bool startsWith(string prefix) {
        class TrieNode* node = root;
        for(const char& c: prefix){
            int ch = c - 'a';
            if(node->children[ch] == nullptr)
                return false;
            
            node = node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
