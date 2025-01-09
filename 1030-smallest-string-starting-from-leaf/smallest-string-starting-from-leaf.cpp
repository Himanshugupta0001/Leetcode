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
    string ans = "";
    void dfs(TreeNode* root, string cur){
        if(root == NULL) return;

        cur = char(root->val + 'a') + cur;

        if(root->left == NULL && root->right == NULL){
            if(ans == "" || ans > cur){
                ans = cur;
            }
            return;
        }

        dfs(root->left, cur);
        dfs(root->right, cur);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, ans);
        return ans;
    }
};