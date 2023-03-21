//complexity: O(m*n * 3^L), where L := max length of words[i]
//O(m*n * 3^L) is from 2D dfs.

//and trie search doesn't take additional L time, because the node in the search process goes along with the 2D dfs process.

//the tricky part is that we use the strings formed by dfs path on the board to trie-search the words, instead of using each word from words to search the board.

//directly modify board for backtracking.

#include<unordered_set>
#include<assert.h>
#define VISITED ('.')

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

    void backtrack_2d_search(vector<vector<char>>& board, const int& i, const int& j, class TrieNode* node, unordered_set<string>& ans_set){
        if(!(0<=i && i<m && 0<=j && j<n)) return;
        if(board[i][j] == VISITED) return;
        
        int ci = board[i][j] - 'a';
        assert(node != nullptr);
        if(node->children[ ci ] == nullptr) return;
        node = node->children[ ci ];

        int backtrack_tmp = board[i][j];
        board[i][j] = VISITED;

        if(node->word_end) ans_set.insert(node->word);

        for(int k=0;k<di.size();k++){
            backtrack_2d_search(board, i+di[k], j+dj[k], node, ans_set);
        }

        board[i][j] = backtrack_tmp;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board.back().size();
        
        class Trie* tr = new Trie(m, n);
        for(const string& word: words) tr->insert(word);

        unordered_set<string> ans_set;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tr->backtrack_2d_search(board, i, j, tr->root, ans_set);
            }
        }

        vector<string> ans;
        for(const string& word: ans_set) ans.push_back(word);
        return ans;
    }
};
