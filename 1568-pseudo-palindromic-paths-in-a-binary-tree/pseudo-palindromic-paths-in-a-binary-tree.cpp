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
    int ans = 0;
    void f(TreeNode* root, vector<int> &hash){
        if(root == NULL){
            return;
        }

        hash[root->val]++;

        if(root->left == NULL && root->right == NULL){
            int oddf = 0;
            for(int i=0 ; i<=9; i++){
                if(hash[i]%2 != 0){
                    oddf++;
                }
            }

            if(oddf <= 1){
                ans++;
            }
        }

        f(root->left, hash);
        f(root->right, hash);

        hash[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10, 0);
        f(root, hash);

        return ans;
    }
};