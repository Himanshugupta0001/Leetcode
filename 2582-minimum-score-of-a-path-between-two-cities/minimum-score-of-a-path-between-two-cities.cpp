class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>> &adj, vector<bool> &visited, int &result){
        visited[node] = true;

        for(auto &it : adj[node]){
            int v = it.first;
            int dis = it.second;

            result = min(result, dis);

            if(!visited[v]){
                dfs(v, adj, visited, result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> visited(n, false);

        int result = INT_MAX;

        dfs(1, adj, visited, result);

        return result;
    }
};