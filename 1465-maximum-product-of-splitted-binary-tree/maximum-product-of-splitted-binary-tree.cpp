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
    long Sum = 0;
    long maxP = 0;

    int totalSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftSubtreeSum = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);

        int sum = root->val + leftSubtreeSum + rightSubtreeSum;

        return sum;
    }

    int find(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftSum = find(root->left);
        int rightSum = find(root->right);
        long subtreeSum = root->val + leftSum + rightSum;

        long remainingSum = Sum - subtreeSum;

        maxP = max(maxP, subtreeSum*remainingSum);

        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        maxP = 0;
        Sum = totalSum(root);

        find(root);
        return maxP%1000000007;
    }
};