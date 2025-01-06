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
    int f(TreeNode* root, int cur){
        if(root == NULL){
            return 0;
        }

        cur = (cur*10) + root->val;

        if(root->left == NULL && root->right == NULL){
            return cur;
        }

        int l = f(root->left, cur);
        int r = f(root->right, cur);

        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return f(root, 0);
    }
};