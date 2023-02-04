/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define test 0 // 1 0
#include<assert.h>
class Codec {
public:
    const string delim = ",";
    const string null = "n";

    void preorder(TreeNode* root, string& serial){
        if(root == nullptr){
            serial += null + delim;
            return;
        }

        serial += to_string(root->val) + delim;
        preorder(root->left, serial);
        preorder(root->right, serial);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial = "";
        preorder(root, serial);
        return serial;
    }

    TreeNode* deserial(const vector<string>& serial, int& i){
        assert(i < serial.size());
        if(serial[i] == null){
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode( stoi( serial[i] ) );
        i++;
        root->left = deserial(serial, i);
        root->right = deserial(serial, i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> serial;
        int low = 0;
        int high = 0;
        while(high < data.size()){
            while(high < data.size() && data.substr(high, 1) != delim){
                high++;
            }

            assert(high-1 < data.size());
            serial.push_back( data.substr(low, (high-1) - (low-1) ) );

            high += delim.size();
            low = high;
        }

        #if test == 1
        for(const string& s: serial)
            cout << s << " ";
        cout << endl;
        #endif

        int i = 0;
        return deserial(serial, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
