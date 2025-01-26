class Solution {
public:
    vector<int> dfs(unordered_map<int, vector<int>> &adj, int cur, int parent, vector<int> &result, string &labels){
        vector<int> my_count(26, 0);
        char myLabel = labels[cur];

        my_count[myLabel - 'a'] = 1;

        for(auto &it : adj[cur]){
            if(it == parent) continue;

            vector<int> child_count(26, 0);

            child_count = dfs(adj, it, cur, result, labels);

            for(int i=0; i<26; i++){
                my_count[i] += child_count[i];
            }
        }
        result[cur] = my_count[myLabel - 'a'];

        return my_count;
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

        dfs(adj, 0, -1, result, labels);

        return result;
    }
};