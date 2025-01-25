class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &adj, int cur, int parent, vector<bool>& hasApple){
        int time = 0;

        for(int &child : adj[cur]){
            if(child == parent){
                continue;
            }

            int timefromchild = dfs(adj, child, cur, hasApple);

            if(timefromchild > 0 || hasApple[child]){
                time += timefromchild + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj, 0, -1, hasApple);
    }
};