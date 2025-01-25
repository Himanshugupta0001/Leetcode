class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& mp, vector<bool> &visited, int src, int dest){
        if(src == dest){
            return true;
        }

        if(visited[src] == true){
            return false;
        }

        visited[src] = true;

        for(auto &it : mp[src]){
            if(dfs(mp, visited, it, dest) == true){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for(vector<int> &it : edges){
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return dfs(mp, visited, source, destination);
    }
};