#define WILDCARD ('.')
#define ALPHABET 26
class TrieNode{
public:
    vector<class TrieNode*> children;
    bool word_end;

    TrieNode(){
        word_end = false;

        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++)
            children[i] = nullptr;
    }
};
class Trie{
public:
    class TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(const string& word){
        if(word.size() == 0)return;
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                node->children[ci] = new TrieNode();
            node = node->children[ci];
        }
        node->word_end = true;
    }

    bool search_wildcard(const string& word, class TrieNode* node=nullptr, int i=0){
        if(i == 0)node = root;
        for(;i<word.size();i++){
            if(word[i] == WILDCARD){
                bool ret = false;
                for(int j=0;j<ALPHABET;j++)if(node->children[j] != nullptr)
                    ret |= search_wildcard(word, node->children[j], i+1);
                return ret;
            }

            int ci = word[i] - 'a';
            if(node->children[ci] == nullptr)
                return false;
            node = node->children[ci];
        }

        return node->word_end;
    }
};

class WordDictionary {
public:
    class Trie* tr;
    WordDictionary() {
        tr = new Trie();
    }
    
    void addWord(string word) {
        tr->insert(word);
    }
    
    bool search(string word) {
        return tr->search_wildcard(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
