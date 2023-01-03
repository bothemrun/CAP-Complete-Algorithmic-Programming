/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define test 0 //1 0
#include<stack>
#include<limits.h>
#include<assert.h>
#include<unordered_map>
#define left_parenthesis (INT_MIN)
#define right_parenthesis (INT_MAX)
class Solution {
public:
    unordered_map<int, int> paren_pair;
    vector<int> tree_int;

    void str2int(const string& s){
        stack<int> left_paren;

        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                left_paren.push( tree_int.size() );//NOTE: before push_back

                tree_int.push_back(left_parenthesis);

                i++;
            }else if(s[i] == ')'){
                assert(left_paren.size() != 0);
                paren_pair[ left_paren.top() ] = tree_int.size();//NOTE: before push_back
                left_paren.pop();

                tree_int.push_back(right_parenthesis);

                i++;
            }else{
                int high = i;
                while(high+1 < s.size() &&
                    ( 
                    s[high + 1] != '(' && 
                    s[high + 1] != ')' 
                    ) 
                ){
                    high++;
                }

                //NOTE: include minus sign
                tree_int.push_back( 
                   stoi( s.substr(i, high - (i-1) ) )
                );

                i = high + 1;
            }
        }
    }

    TreeNode* preorder(const int& first_paren, const int& last_paren){
        assert(first_paren + 1 < tree_int.size());
        TreeNode* root = new TreeNode( tree_int[ first_paren + 1 ] );
        
        if(first_paren + 2 == last_paren)return root;


        //NOTE: now has at least 1 child
        int l_first_paren = first_paren + 2;
        int l_last_paren = paren_pair[ l_first_paren ];

        root->left = preorder(l_first_paren, l_last_paren);


        int r_first_paren = l_last_paren + 1;
        int r_last_paren = last_paren - 1;

        if(l_last_paren + 1 != last_paren){
            //NOTE: has right child
            root->right = preorder(r_first_paren, r_last_paren);
        }

        return root;

        
    }

    TreeNode* str2tree(string s) {
        s = "(" + s + ")";
        str2int(s);

        #if test == 1
        for(const int& x: tree_int){
            if(x == left_parenthesis)
                cout << "(";
            else if(x == right_parenthesis)
                cout << ")";
            else cout << x;
        }
        cout << endl << endl;
        #endif

        //NOTE:
        if(s == "()")return nullptr;

        return preorder(0, tree_int.size()-1);
    }
};



