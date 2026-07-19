/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>queue;
        queue.push(p);
        queue.push(q);
         if (p == NULL && q== NULL) {
            return true;
            }
        while (!queue.empty()) {
            TreeNode* first = queue.front();
            queue.pop();
            TreeNode* second = queue.front();
            queue.pop();
            if (first == NULL && second == NULL) {
                continue;
            }
            if (first == NULL || second == NULL || first->val != second->val) {
                return false;
            }
            queue.push(first->left);
            queue.push(second->left);
            queue.push(first->right);
            queue.push(second->right);
        }
     return true;
      
    }
};