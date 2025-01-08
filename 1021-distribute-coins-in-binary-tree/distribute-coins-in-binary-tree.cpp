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
    int f(TreeNode* root, int &moves){
        if(root == NULL){
            return 0;
        }

        int l = f(root->left, moves);
        int r = f(root->right, moves);

        moves += abs(l) + abs(r);

        return (l+r+root->val) - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        f(root, moves);

        return moves;
    }
};