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
    int result;
    pair<int, int> f(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }

        auto p1 = f(root->left);
        auto p2 = f(root->right);

        int sum = p1.first + p2.first + root->val;
        int cnt = p1.second + p2.second + 1;

        int avg = sum/cnt;
        if(avg == root->val){
            result += 1;
        }

        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        f(root);
        return result;
    }
};