//m0
//O(nlogn) for deserialization
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<assert.h>
class Codec {
public:
    const string delim = ",";

    // Encodes a tree to a single string.
    void preorder(TreeNode* root, string& serial){
        if(root == nullptr)return;

        serial += to_string(root->val) + delim;
        preorder(root->left, serial);
        preorder(root->right, serial);
    }
    string serialize(TreeNode* root) {
        string serial = "";
        preorder(root, serial);
        return serial;
    }


    // Decodes your encoded data to tree.
    inline void split(const string& data, vector<string>& serial, const string& delim){
        int end;
        int start = 0;
        while( (end = data.find(delim, start)) != string::npos){
            serial.push_back( data.substr(start, (end-1) - (start-1) ) );
            start = end + delim.size();
        }
        if(start < data.size()) serial.push_back( data.substr(start) );
    }

    void search_bst(TreeNode* root, const int& val){
        assert(root != nullptr);
        if(val < root->val){
            if(root->left == nullptr)
                root->left = new TreeNode(val);
            else search_bst(root->left, val);
        }else{
            if(root->right == nullptr)
                root->right = new TreeNode(val);
            else search_bst(root->right, val);
        }
    }
    TreeNode* deserial(const vector<string>& serial){
        if(serial.size() == 0)return nullptr;

        TreeNode* root = new TreeNode( stoi( serial.front() ) );

        for(int i=1;i<serial.size();i++)
            search_bst(root, stoi(serial[i]) );
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string> serial;
        split(data, serial, delim);

        return deserial(serial);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
