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

        string rootToSrc = "";
        string rootToDest = "";

        findPath(root, startValue, rootToSrc);
        findPath(root, destValue, rootToDest);

        int l = 0;
        while(l < rootToSrc.size() && l < rootToDest.size() && rootToSrc[l] == rootToDest[l]){
            l++;
        }

        string result = "";
        for(int i=0; i<rootToSrc.size() - l; i++){
            result.push_back('U');
        }

        for(int i=l; i<rootToDest.size(); i++){
            result.push_back(rootToDest[i]);
        }

        return result;
    }
};