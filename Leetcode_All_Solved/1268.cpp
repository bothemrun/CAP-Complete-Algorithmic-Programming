#define ALPHABET 26
class TrieNode{
public:
    vector<class TrieNode*> children;
    bool word_end;
    string word;
    TrieNode(){
        word_end = false;

        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++) children[i] = nullptr;
    }

    ~TrieNode(){
        for(class TrieNode* tn: children)
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

        node->word = word;
    }

    inline class TrieNode* search(const string& prefix){
        class TrieNode* node = root;
        for(const char& c: prefix){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)return nullptr;
            node = node->children[ci];
        }
        return node;
    }

    inline bool match_cnt(class TrieNode* node, int& cnt, vector<string>& matches, const int& max_match=3){
        if(node == nullptr)return false;

        if(node->word_end){
            cnt++;
            matches.push_back(node->word);
            //NOTE: not return
        }

        if(cnt == max_match)return true;

        for(class TrieNode* tn: node->children)if(tn != nullptr){
            if( match_cnt(tn, cnt, matches) )return true;
        }
        return false;
    }

    inline void match_prefix(const string& prefix, vector<string>& matches){
        class TrieNode* node = search(prefix);

        int cnt = 0;
        match_cnt(node, cnt, matches);
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        class Trie* tr = new Trie();
        for(const string& s: products) tr->insert(s);

        vector<vector<string>> ans;
        string s = "";
        for(const char& c: searchWord){
            s += c;
            vector<string> matches;
            tr->match_prefix(s, matches);
            ans.push_back(matches);
        }
        return ans;
    }
};
