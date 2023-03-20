#include<unordered_map>
class TrieNode{
public:
    unordered_map<string, class TrieNode*> children;
    bool word_end;

    TrieNode(){
        word_end = false;
    }
};
class Trie{
public:
    class TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(const vector<string>& words){
        class TrieNode* node = root;
        for(const string& s: words){
            if(node->children.count(s) == 0)
                node->children[s] = new TrieNode();
            node = node->children[s];
        }
        node->word_end = true;
    }

    bool search_prefix(const vector<string>& words){
        class TrieNode* node = root;
        for(int i=0;i<words.size();i++){
            if(node->children.count(words[i]) == 0)
                return false;
            node = node->children[words[i]];

            if(i != words.size()-1 && node->word_end == true)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    inline void split(const string& s, vector<string>& v, const string& delim="/"){
        int start = 0, end;
        while((end = s.find(delim, start)) != string::npos){
            v.push_back(s.substr(start, (end-1) - (start-1) ));
            start = end + delim.size();
        }
        if(start < s.size()) v.push_back(s.substr(start));
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        vector<vector<string>> folder_v;
        for(const string& s: folder){
            vector<string> v;
            split(s, v);
            folder_v.push_back(v);
        }
        

        class Trie* tr = new Trie();
        for(const vector<string>& words: folder_v)
            tr->insert(words);
        
        
        vector<string> ans;
        for(int i=0;i<folder.size();i++)if(tr->search_prefix(folder_v[i]) == false)
            ans.push_back(folder[i]);
        return ans;
    }
};
