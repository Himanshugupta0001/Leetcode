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
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root == NULL || p == root->val || q == root->val){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
    bool findPath(TreeNode* LCA, int target, string &path){
        if(LCA == NULL){
            return false;
        }

        if(LCA->val == target){
            return true;
        }

        path.push_back('L');
        if(findPath(LCA->left, target, path) == true){
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if(findPath(LCA->right, target, path) == true){
            return true;
        }

        path.pop_back();

        return false;

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string lcaToSrc = "";
        string lcaToDest = "";

        findPath(LCA, startValue, lcaToSrc);
        findPath(LCA, destValue, lcaToDest);

        string result = "";
        for(int i=0; i<lcaToSrc.size(); i++){
            result.push_back('U');
        }

        result += lcaToDest;

        return result;
    }
};