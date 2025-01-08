class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> childToParent;

        for(int i=0; i<n; i++){
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1){
                adj[node].push_back(leftC);
                if(childToParent.find(leftC) != childToParent.end()){
                    return false;
                }
                childToParent[leftC] = node;
            }

            if(rightC != -1){
                adj[node].push_back(rightC);
                if(childToParent.find(rightC) != childToParent.end()){
                    return false;
                }
                childToParent[rightC] = node;
            }
        }

        int root = -1;
        for(int i=0; i<n; i++){
            if(childToParent.find(i) == childToParent.end()){
                if(root != -1){
                    return false;
                }
                root = i;
            }
        }

        if(root == -1){
            return false;
        }

        int cnt = 0;
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        cnt = 1;
        visited[root] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &v : adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    cnt++;
                    q.push(v);
                }
            }
        }
        return cnt == n;
    }
};