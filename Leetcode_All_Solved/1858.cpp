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
    void insert(const string& word){
        class TrieNode* node = root;
        for(const char& c: word){
            int ch = c - 'a';
            if(node->children[ch] == nullptr)
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->word_end = true;
    }
    bool all_prefix(const string& word){
        class TrieNode* node = root;
        for(const char& c: word){
            int ch = c - 'a';
            if(node->children[ch] == nullptr)
                return false;
            
            //NOTE:
            node = node->children[ch];
            if(node->word_end == false)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        class Trie* tr = new Trie();
        for(const string& w: words) tr->insert(w);
        int max_len = 0;
        vector<string> same_len;
        for(const string& w: words){
            if(tr->all_prefix(w)){
                if(w.size() > max_len){
                    max_len = w.size();
                    same_len.clear();
                    same_len.push_back(w);
                }else if(w.size() == max_len)
                    same_len.push_back(w);
            }
        }

        if(same_len.size() == 0)return "";
        //NOTE: min_element() for string
        return *min_element(same_len.begin(), same_len.end());
    }
};
