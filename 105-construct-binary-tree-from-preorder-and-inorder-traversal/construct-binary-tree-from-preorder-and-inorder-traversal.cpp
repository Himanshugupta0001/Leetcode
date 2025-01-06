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
    TreeNode* f(vector<int>& preorder, vector<int>& inorder, int start, int end, int &ind){
        if(start > end) return NULL;

        int rootVal = preorder[ind];
        int i = start;

        for(; i<=end; i++){
            if(inorder[i] == rootVal){
                break;
            }
        }
        ind++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = f(preorder, inorder, start, i-1, ind);
        root->right = f(preorder, inorder, i+1, end, ind);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int ind = 0;
        return f(preorder, inorder, 0, n-1, ind);
    }
};