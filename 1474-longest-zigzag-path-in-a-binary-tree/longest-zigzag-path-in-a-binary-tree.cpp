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
    int maxPath = 0;
    void f(TreeNode* root, int left, int right){
        if(root == NULL) return;

        maxPath = max({maxPath, left, right});

        f(root->left, right+1, 0);
        f(root->right, 0, left+1);
        
    }
    int longestZigZag(TreeNode* root) {
        f(root, 0, 0);
        return maxPath;
    }
};