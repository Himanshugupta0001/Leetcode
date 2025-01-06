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
    void f(TreeNode* root, int steps, bool goLeft){
        if(root == NULL) return;

        maxPath = max(maxPath, steps);
        if(goLeft == true){
            f(root->left, steps+1, false);
            f(root->right, 1, true);
        }
        else{
            f(root->right, steps+1, true);
            f(root->left, 1, false);
        }
    }
    int longestZigZag(TreeNode* root) {
        f(root, 0, true);
        f(root, 0, false);
        return maxPath;
    }
};