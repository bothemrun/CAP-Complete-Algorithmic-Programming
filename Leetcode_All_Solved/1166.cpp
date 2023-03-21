#include<unordered_map>
class TrieNode{
public:
    unordered_map<string, class TrieNode*> children;
    bool word_end;
    int value;
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
    inline void insert(const vector<string>& word, const int& value){
        class TrieNode* node = root;
        for(const string& s: word){
            if(node->children.count(s) == 0)
                node->children[s] = new TrieNode();
            node = node->children[s];
        }
        node->word_end = true;
        node->value = value;
    }
    inline class TrieNode* search(const vector<string>& v, const int& v_high){
        class TrieNode* node = root;
        for(int i=0;i<=v_high;i++){
            if(node->children.count(v[i]) == 0)
                return nullptr;
            node = node->children[v[i]];
        }
        return node;
    }
};

class FileSystem {
public:
    class Trie* tr;
    FileSystem() {
        tr = new Trie();
    }
    
    inline void split(const string& path, vector<string>& v, const string& delim="/"){
        int start = 1, end;//NOTE: skip first /
        while((end = path.find(delim, start)) != string::npos){
            v.push_back(path.substr(start, (end-1) - (start-1) ));
            start = end + delim.size();
        }
        if(start < path.size()) v.push_back(path.substr(start));
    }

    bool createPath(string path, int value) {
        vector<string> v;
        split(path, v);

        if(v.size() == 1){
            if(tr->search(v, v.size()-1))return false;
        }else{
            class TrieNode* parent = tr->search(v, v.size()-1 - 1);
            if(parent == nullptr) return false;
            if(parent->children.count(v.back()) != 0 && parent->children[v.back()]->word_end == true) return false;
        }

        tr->insert(v, value);
        return true;
    }
    
    int get(string path) {
        vector<string> v;
        split(path, v);
        
        class TrieNode* node = tr->search(v, v.size()-1);
        if(node == nullptr || node->word_end == false)return (-1);
        return node->value;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
