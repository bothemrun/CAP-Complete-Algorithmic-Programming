/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    const string delim = ",";
    const string null = "n";

    // Encodes a tree to a single string.
    void preorder1(TreeNode* root, string& serial){
        if(root == nullptr){
            serial += null + delim;
            return;
        }

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
    TreeNode* preorder2(const vector<string>& serial, int& i){
        if(serial.at(i) == null){
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode( stoi(serial[i]) );
        i++;

        root->left = preorder2(serial, i);
        root->right = preorder2(serial, i);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string> serial;
        split(data, serial, delim);

        int i = 0;
        return preorder2(serial, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
