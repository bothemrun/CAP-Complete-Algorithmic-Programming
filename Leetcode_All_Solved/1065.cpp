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
class Trie{
public:
    class TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    bool search(const string& word){
        class TrieNode* node = root;
        for(const char& c: word){
            int ch = c - 'a';
            if(node->children[ch] == nullptr)
                return false;
            node = node->children[ch];
        }
        return node->word_end;
    }
    void insert(const string& word){
        if(search(word)) return;
        
        class TrieNode* node = root;
        for(const char& c: word){
            int ch = c - 'a';
            if(node->children[ch] == nullptr)
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->word_end = true;
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        class Trie* tr = new Trie();
        for(const string& w: words) tr->insert(w);

        int n = text.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            string w = "";
            for(int j=i;j<n;j++){
                w += text[j];
                if(tr->search(w)) ans.push_back(vector<int>({i, j}));
            }
        }
        return ans;
    }
};
