//m2
//optim from m1 & m0: erase() after having found the word --> avoid repetitive work.
//erase() implementation method: simply set word_end = false

//m1
//optim from m0: don't copy the word strings, use address.

//complexity: O(m*n * 3^L), where L := max length of words[i]
//O(m*n * 3^L) is from 2D dfs.

//and trie search doesn't take additional L time, because the node in the search process goes along with the 2D dfs process.

//the tricky part is that we use the strings formed by dfs path on the board to trie-search the words, instead of using each word from words to search the board.

//directly modify board for backtracking.

#define VISITED ('.')
#include<assert.h>

#define ALPHABET 26
class TrieNode{
public:
    vector<class TrieNode*> children;
    bool word_end;

    string* word_addr;//optim

    TrieNode(){
        word_end = false;
        children.resize(ALPHABET);
        for(int i=0;i<ALPHABET;i++) children[i] = nullptr;
    }
    ~TrieNode(){
        for(class TrieNode* tn: children)if(tn)
            delete tn;
    }
};
class Trie{
public:
    class TrieNode* root;
    int m, n;
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

    Trie(const int& m, const int& n){
        root = new TrieNode();
        this->m = m;
        this->n = n;
    }
    inline void insert(const string& word, string* word_addr){
        class TrieNode* node = root;
        for(const char& c: word){
            int ci = c - 'a';
            if(node->children[ci] == nullptr)
                node->children[ci] = new TrieNode();
            node = node->children[ci];
        }
        node->word_end = true;

        node->word_addr = word_addr;
    }

    inline void erase(class TrieNode* node){
        node->word_end = false;
    }

    void backtrack_2d_search(vector<vector<char>>& board, const int& i, const int& j, class TrieNode* node, vector<string>& ans){
        if(!(0<=i && i<m && 0<=j && j<n)) return;
        if(board[i][j] == VISITED) return;

        int ci = board[i][j] - 'a';
        assert(node != nullptr);
        if(node->children[ci] == nullptr) return;
        node = node->children[ci];

        if(node->word_end){
            ans.push_back(*node->word_addr);
            
            //NOTE: optim
            erase(node);
        }

        char backtrack_tmp = board[i][j];
        board[i][j] = VISITED;
        for(int k=0;k<di.size();k++)
            backtrack_2d_search(board, i+di[k], j+dj[k], node, ans);
        board[i][j] = backtrack_tmp;
    }
};

class Solution {
public:
    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board.back().size();

        class Trie* tr = new Trie(m, n);
        for(string& word: words) tr->insert(word, &word);

        vector<string> ans;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                tr->backtrack_2d_search(board, i, j, tr->root, ans);
        return ans;
    }
};
