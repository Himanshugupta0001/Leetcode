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
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> q;
        q.push({root, string(1, char(root->val + 'a'))});

        string ans ="";

        while(!q.empty()){
            auto [node, cur] = q.front();
            q.pop();

            if(node->left == NULL && node->right == NULL){
                if(ans == "" || ans > cur){
                    ans = cur;
                }
            }

            if(node->left){
                q.push({node->left, char(node->left->val + 'a') + cur});
            }

            if(node->right){
                q.push({node->right, char(node->right->val + 'a') + cur});
            }
        }
        return ans;
    }
};