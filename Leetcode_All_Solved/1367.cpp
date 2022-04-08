/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
private:
    bool check_preorder(TreeNode* root, ListNode* head){
        if(head == nullptr)return true;
        if(root == nullptr)return false;
        if(root->val != head->val)return false;
        return check_preorder(root->left, head->next) || check_preorder(root->right, head->next);
    }
    bool find_preorder(TreeNode* root, ListNode* head){
        if(root == nullptr)return false;
        if(root->val == head->val && check_preorder(root, head) == true)return true;
        return find_preorder(root->left, head) || find_preorder(root->right, head);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return find_preorder(root, head);
    }
};
