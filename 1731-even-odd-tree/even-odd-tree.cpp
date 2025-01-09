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
    vector<int> levelPrev;
    bool f(TreeNode* root, int level){
        if(root == NULL){
            return true;
        }

        if(level % 2 == root->val % 2){
            return false;
        }

        if(level >= levelPrev.size()){
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0){
            if(level % 2 == 0 && root->val <= levelPrev[level] || level % 2 != 0 && root->val >= levelPrev[level]){
                return false;
            }
        }

        levelPrev[level] = root->val;

        return f(root->left, level+1) && f(root->right, level+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        return f(root, 0);
    }
};