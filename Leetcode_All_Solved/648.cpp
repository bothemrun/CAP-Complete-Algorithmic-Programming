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
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                node->children[ci] = new TrieNode();
            node = node->children[ci];
        }
        node->word_end = true;
    }

    string search_prefix(const string& word){
        class TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            int ci = word[i] - 'a';
            if(node->children[ci] == nullptr)return "";
            node = node->children[ci];

            if(node->word_end == true)
                return word.substr(0, i+1);
        }
        if(node->word_end) return word;
        else return "";
    }
};

class Solution {
public:
    inline void split(const string& s, vector<string>& v, const string& delim=" "){
        int start = 0, end;
        while((end = s.find(delim, start)) != string::npos){
            v.push_back(s.substr(start, (end-1) - (start-1) ));
            start = end + delim.size();
        }
        if(start < s.size()) v.push_back(s.substr(start));
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        class Trie* tr = new Trie();
        for(const string& w: dictionary)
            tr->insert(w);
        
        vector<string> sentence_v;
        split(sentence, sentence_v);

        string ans = "";
        string root;
        for(const string& s: sentence_v){
            if( (root = tr->search_prefix(s) ) != "" )
                ans += root + " ";
            else ans += s + " ";
        }
        ans.erase(ans.size()-1, 1);
        return ans;
    }
};
