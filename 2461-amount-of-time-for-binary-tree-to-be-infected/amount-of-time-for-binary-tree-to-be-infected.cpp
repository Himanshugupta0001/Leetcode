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
    TreeNode* markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int &target){
        queue<TreeNode*> q;
        TreeNode* targetNode = NULL;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            
            if(current->val == target){
                targetNode = current;
            }
            
            if(current->left){
                q.push(current->left);
                parent_track[current->left] = current;
            }
            if(current->right){
                q.push(current->right);
                parent_track[current->right] = current;
            }
        }
        return targetNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        TreeNode* targetNode = markParent(root, parent_track, start);
        
        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({targetNode, 0});
        visited[targetNode] = true;
        
        int t = 0;
        
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int ti = q.front().second;
            q.pop();
            
            t = max(t, ti);
            
            if(cur->left && !visited[cur->left]){
                q.push({cur->left, ti+1});
                visited[cur->left] = true;
            }
            
            if(cur->right && !visited[cur->right]){
                q.push({cur->right, ti+1});
                visited[cur->right] = true;
            }
            
            if(parent_track[cur] && !visited[parent_track[cur]]){
                q.push({parent_track[cur], ti+1});
                visited[parent_track[cur]] = true;
            }
        }
        return t;
    }
};