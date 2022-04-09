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
#include<queue>
class CBTInserter {
private:
    TreeNode* Root;
    queue<TreeNode*> available;
public:
    CBTInserter(TreeNode* root) {
        this->Root = root;
        
        //NOTE: level order, push available
        queue<TreeNode*> q_tmp;
        q_tmp.push(root);
        while(q_tmp.size() != 0){
            int level_size = q_tmp.size();
            for(int i=0;i<level_size;i++){
                TreeNode* n = q_tmp.front();
                q_tmp.pop();
                
                //NOTE:
                if(n->left == nullptr || n->right == nullptr)this->available.push(n);
                
                if(n->left != nullptr)q_tmp.push(n->left);
                if(n->right != nullptr)q_tmp.push(n->right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* new_node = new TreeNode(val);
        TreeNode* avail = this->available.front();
        if(avail->left == nullptr)avail->left = new_node;
        else{
            avail->right = new_node;
            this->available.pop();
        }
        
        this->available.push(new_node);
        
        return avail->val;
    }
    
    TreeNode* get_root() {
        return this->Root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
