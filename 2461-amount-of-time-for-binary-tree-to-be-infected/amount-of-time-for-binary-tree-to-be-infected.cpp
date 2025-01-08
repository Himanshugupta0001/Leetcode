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
    int f(TreeNode* root, int start){
        if(root == NULL){
            return 0;
        }

        int lh = f(root->left, start);
        int rh = f(root->right, start);

        if(root->val == start){
            result = max(lh, rh);

            return -1;
        }
        else if(lh >= 0 && rh >= 0){
            return max(lh, rh) + 1;
        }
        else{
            int d = abs(lh) + abs(rh);
            result = max(result, d);

            return min(lh, rh) - 1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        f(root, start);

        return result;
    }
};