class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int node, int parent, vector<int> &result, string &labels, vector<int> &count){
        char myLabel = labels[node];

        int count_before_visiting_node_children = count[myLabel - 'a'];

        count[myLabel - 'a'] += 1;
        for(auto &it : adj[node]){
            if(it == parent){
                continue;
            }

            dfs(adj, it, node, result, labels, count);
        }

        int count_after_visiting_node_children = count[myLabel - 'a'];

        result[node] = count_after_visiting_node_children - count_before_visiting_node_children;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adj;
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n, 0);
        vector<int> count(26, 0);

        dfs(adj, 0, -1, result, labels, count);

        return result;
    }
};