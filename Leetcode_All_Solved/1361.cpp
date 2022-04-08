class Solution {
private:
    bool preorder(int root, const vector<int>& leftChild, const vector<int>& rightChild, vector<bool>& visited){
        if(root == (-1))return true;
        
        if(visited.at(root) == true)return false;
        visited.at(root) = true;
        return preorder(leftChild.at(root), leftChild, rightChild, visited) && preorder(rightChild.at(root), leftChild, rightChild, visited);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //find root
        vector<bool> parent (n, false);
        for(int i=0;i<n;i++){
            if(leftChild[i] != (-1))parent[leftChild[i]] = true;
            if(rightChild[i] != (-1))parent[rightChild[i]] = true;
        }
        int root = (-1);
        for(int i=0;i<n;i++)if(parent[i] == false)root = i;
        //NOTE: cyclic : every node has parent
        if(root == (-1))return false;
        
        //NOTE: illegal : 2 parents, cyclic, disconnected --> so order traversal, to see if visited exactly once
        vector<bool> visited (n, false);
        bool legal = preorder(root, leftChild, rightChild, visited);//NOTE: cyclic
        //NOTE: 2 parents, disconnected
        for(const bool& v:visited)if(v == false){
            legal = false;
            break;
        }
        return legal;
    }
};
