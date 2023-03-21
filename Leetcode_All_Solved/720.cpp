#include<algorithm>
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
    inline bool prefix_all_word_end(const string& word){
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)return false;
            node = node->children[ci];
            
            if(node->word_end == false)return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        class Trie* tr = new Trie();
        for(const string& word: words) tr->insert(word);
        string longest = "";
        for(const string& word: words)if(word.size() > longest.size() || 
        (word.size() == longest.size() && word < longest) ){
            if(tr->prefix_all_word_end(word))
                longest = word;
        }
        return longest;
    }
};
