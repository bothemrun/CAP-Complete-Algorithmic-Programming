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
#define test 1 //1 0
#include<assert.h>
class Codec {
public:
    const string delim = ",";
    const string child_end = "n";

    // Encodes a tree to a single string.
    void preorder1(Node* root, string& serial){
        assert(root != nullptr);

        serial += to_string(root->val) + delim;
        for(Node* child: root->children){
            //assert(child != nullptr);
            preorder1(child, serial);
        }
        serial += child_end + delim;
    }
    string serialize(Node* root) {
        string serial = "";
        if(root == nullptr)return "";//edge case
        preorder1(root, serial);
        
        #if test == 1
        cout << serial << endl;
        #endif

        return serial;
    }
	
    // Decodes your encoded data to tree.
    inline void split(const string& data, vector<string>& serial, const string& delim){
        int end;
        int start = 0;
        while( (end = data.find(delim, start)) != string::npos ){
            serial.push_back( data.substr(start, (end-1) - (start-1) ) );
            start = end + delim.size();
        }
        //actually not needed in this problem
        serial.push_back( data.substr(start) );
    }
    Node* preorder2(const vector<string>& serial, int& i){
        assert(i < serial.size());

        if(serial.at(i) == child_end){
            i++;
            return nullptr;
        }

        Node* root = new Node( stoi(serial[i]) );
        i++;
        Node* child_ret;
        while( (child_ret = preorder2(serial, i)) != nullptr ){
            root->children.push_back(child_ret);
        }
        return root;
    }
    Node* deserialize(string data) {
        if(data == "")return nullptr;//edge case

        vector<string> serial;
        split(data, serial, delim);
        int i = 0;
        return preorder2(serial, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
