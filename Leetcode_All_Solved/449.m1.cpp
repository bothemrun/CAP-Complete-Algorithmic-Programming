//m1
//deserialization in O(n)
//https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<limits.h>
class Codec {
public:
    const string delim = ",";

    // Encodes a tree to a single string.
    void preorder1(TreeNode* root, string& serial){
        if(root == nullptr)return;
        
        serial += to_string(root->val) + delim;
        preorder1(root->left, serial);
        preorder1(root->right, serial);
    }
    string serialize(TreeNode* root) {
        string serial = "";
        preorder1(root, serial);
        return serial;
    }

    // Decodes your encoded data to tree.
    inline void split(const string& s, vector<string>& serial, const string& delim){
        int start = 0, end;
        while( (end = s.find(delim, start)) != string::npos){
            serial.push_back( s.substr(start, (end-1) - (start-1) ) );
            start = end + delim.size();
        }
        if(start < s.size()) serial.push_back( s.substr(start) );
    }
    TreeNode* preorder_range(const vector<string>& serial, int& i, const int& min_val, const int& max_val){
        if(!(i < serial.size())) return nullptr;

        int val = stoi(serial[i]);
        if(!(min_val <= val && val <= max_val)) return nullptr;
        TreeNode *root = new TreeNode(val);
        i++;

        if(i < serial.size())
            root->left = preorder_range(serial, i, min_val, val);
        if(i < serial.size())
            root->right = preorder_range(serial, i, val, max_val);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string> serial;
        split(data, serial, delim);

        int i = 0;
        return preorder_range(serial, i, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
