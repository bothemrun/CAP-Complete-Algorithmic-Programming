//m1
//trie node with fast array init
#define ALPHABET 26
class TrieNode{
public:
    class TrieNode* children[ALPHABET];
    bool word_end = false;
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

    inline void search_all_prefix(const string& text, const int& start, vector<vector<int>>& ans){
        class TrieNode* node = root;
        for(int i=start;i<text.size();i++){
            int ci = text[i] - 'a';
            if(node->children[ci] == nullptr)return;
            node = node->children[ci];

            if(node->word_end) ans.push_back(vector<int>{start, i});
        }
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        class Trie* tr = new Trie();
        for(const string& word: words) tr->insert(word);

        vector<vector<int>> ans;
        for(int i=0;i<text.size();i++)
            tr->search_all_prefix(text, i, ans);
        return ans;
    }
};
