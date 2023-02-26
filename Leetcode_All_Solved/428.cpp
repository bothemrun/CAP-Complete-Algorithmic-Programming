/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    const string delim = ",";
    const string child_end = "e";

    // Encodes a tree to a single string.
    void preorder1(Node* root, string& serial){
        serial += to_string(root->val) + delim;
        for(Node* child: root->children)
            preorder1(child, serial);
        serial += child_end + delim;
    }
    string serialize(Node* root) {
        string serial = "";
        if(root == nullptr) return child_end;
        
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

    Node* preorder2(const vector<string>& serial, int& i){
        if(serial.at(i) == child_end){
            i++;
            return nullptr;
        }

        Node* root = new Node( stoi(serial[i]) );
        i++;
        
        Node* child_ret;
        while( (child_ret = preorder2(serial, i)) != nullptr)
            root->children.push_back(child_ret);
        return root;
    }
    Node* deserialize(string data) {
        vector<string> serial;
        split(data, serial, delim);

        int i = 0;
        return preorder2(serial, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
