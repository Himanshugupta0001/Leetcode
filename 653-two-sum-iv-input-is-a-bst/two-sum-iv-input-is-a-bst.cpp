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

class BSTIterator {
    stack<TreeNode*> st;
    //reverse->true -> before
    //reverse->false ->next
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = st.top();
        st.pop();
        if(!reverse) pushAll(tempNode->right);
        else pushAll(tempNode->left);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private: 
    void pushAll(TreeNode* Node){
        while(Node != NULL){
            st.push(Node);
            if(reverse == true){
                Node = Node->right;
            }
            else{
                Node = Node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        //for next
        BSTIterator l(root, false);
        //for before
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};