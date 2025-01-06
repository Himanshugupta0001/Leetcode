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
    TreeNode* f(TreeNode* root, int val, int depth, int cur){
        if(root == NULL){
            return NULL;
        }

        if(cur == depth-1){
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftNode;
            root->right->right = rightNode;

            return root;
        }

        root->left = f(root->left, val, depth, cur+1);
        root->right = f(root->right, val, depth, cur+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;

            return newNode;
        }

        int cur = 1;
        return f(root, val, depth, cur);
    }
};