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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child_set;

        for(vector<int> &v : descriptions){
            int parent = v[0];
            int child = v[1];
            int isLeft = v[2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1){
                mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }

            child_set.insert(child);
        }

        for(vector<int> &v : descriptions){
            int parent = v[0];
            if(child_set.find(parent) == child_set.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};