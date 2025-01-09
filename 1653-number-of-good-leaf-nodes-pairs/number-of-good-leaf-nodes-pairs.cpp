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
    vector<int> f(TreeNode* root, int &distance, int &goodLeafNodes){
        if(root == NULL){
            return {0};
        }

        if(root->left == NULL && root->right == NULL){
            return {1};
        }

        vector<int> left_d = f(root->left, distance, goodLeafNodes);
        vector<int> right_d = f(root->right, distance, goodLeafNodes);

        for(int &l : left_d){
            for(int &r : right_d){
                if(l != 0 && r != 0 && l + r <= distance){
                    goodLeafNodes++;
                }
            }
        }

        vector<int> curr_d;
        for(int &l : left_d){
            if(l != 0 && l + 1 <= distance){
                curr_d.push_back(l+1);
            }
        }

        for(int &r : right_d){
            if(r != 0 && r + 1 <= distance){
                curr_d.push_back(r+1);
            }
        }
        return curr_d;
    }
    int countPairs(TreeNode* root, int distance) {
        int goodLeafNodes = 0;
        f(root, distance, goodLeafNodes);

        return goodLeafNodes;
    }
};