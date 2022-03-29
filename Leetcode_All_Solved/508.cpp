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
#include<unordered_map>
class Solution {
private:
    unordered_map<int,int> sum2time;
    int postorder_sum(TreeNode* root){
        if(root == nullptr)return 0;
        
        int l_sum = postorder_sum(root->left);
        int r_sum = postorder_sum(root->right);
        
        int sum = root->val + l_sum + r_sum;
        if(this->sum2time.find(sum) == this->sum2time.end())this->sum2time[sum] = 1;
        else this->sum2time[sum]++;
        return sum;
    }
    vector<int> get_max_time(){
        int max_time = 0;
        vector<int> ans;
        for(unordered_map<int,int>::iterator it=this->sum2time.begin();it != this->sum2time.end();it++){
            if(it->second > max_time){
                max_time = it->second;
                ans.clear();
                ans.push_back(it->first);
            }else if(it->second == max_time)ans.push_back(it->first);
        }
        return ans;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postorder_sum(root);
        return get_max_time();
    }
};
