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
public:
     int count(TreeNode*root,int maxValue){
        if(root==nullptr){
            return 0;

        }
     int good=0;
        if(root->val>=maxValue){
            good=1;
        }
        maxValue=max(maxValue,root->val);
        return good+count(root->left,maxValue)+count(root->right,maxValue);
     } 
    
    int goodNodes(TreeNode* root) {
      int ans=  count(root,root->val);
      return ans;
    }
};