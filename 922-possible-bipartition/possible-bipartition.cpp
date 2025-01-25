class Solution {
public:
    bool bfs(unordered_map<int, vector<int>> &mp, int node, vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : mp[u]){
                if(color[v] == color[u]){
                    return false;
                }
                if(color[v] == -1){
                    q.push(v);
                    color[v] = 1 - color[u];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;
        for(vector<int> &it : dislikes){
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                if(bfs(mp, i, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};