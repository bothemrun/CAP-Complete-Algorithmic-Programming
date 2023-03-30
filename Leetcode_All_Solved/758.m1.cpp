//m1
//better logic for bold tags
#include<assert.h>
#define bold_start ("<b>")
#define bold_end ("</b>")

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
    ~TrieNode(){
        for(class TrieNode* tn: children)if(tn) delete tn;
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
    void search_deepest_end(const string& s, vector<int>& sweep, const int& start){
        class TrieNode* node = root;
        int deepest_end = (-1);
        for(int i=start;i<s.size();i++){
            int ci = s[i] - 'a';
            if(node->children[ci] == nullptr) break;
            node = node->children[ci];

            if(node->word_end == true)
                deepest_end = i;
        }

        if(deepest_end != (-1)){
            sweep[start]++;
            assert(deepest_end + 1 < sweep.size());
            sweep[deepest_end + 1]--;
        }
    }
};

class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        class Trie* tr = new Trie();
        for(const string& word: words) tr->insert(word);

        vector<int> sweep(n + 1, 0);
        for(int start=0;start<n;start++){
            tr->search_deepest_end(s, sweep, start);
        }


        //NOTE: 1D sweep line
        //NOTE: didn't use the version with priority queue, 'cuz O(n) < O(nlogn), where n := s.size()
        vector<bool> sweep_bold(n, false);
        int cur_sweep = 0;
        for(int i=0;i<n;i++){
            cur_sweep += sweep[i];
            if(cur_sweep > 0) sweep_bold[i] = true;
        }

        //NOTE: many edge cases for bold
        string s_bold = "";
        //if(sweep_bold[0]) s_bold += bold_start;
        for(int i=0;i<n;i++){
            if(sweep_bold[i] && ( !(0<=i-1) || sweep_bold[i-1] == false ) )
                s_bold += bold_start;
            
            s_bold += s[i];

            if(sweep_bold[i] && ( !(i+1<n) || sweep_bold[i+1] == false ) )
                s_bold += bold_end;

            /*s_bold += s[i];

            if(sweep_bold[i] == false && i+1 < n && sweep_bold[i+1])
                s_bold += bold_start;
            if(sweep_bold[i] && (i+1==n || sweep_bold[i+1] == false) )
                s_bold += bold_end;*/
        }
        return s_bold;
    }
};
