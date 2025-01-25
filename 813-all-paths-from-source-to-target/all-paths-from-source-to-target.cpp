class Solution {
public:
    void dfs(vector<vector<int>>& graph, int u, int target, vector<vector<int>> &ans, vector<int> &temp){
        temp.push_back(u);

        if(u == target){
            ans.push_back(temp);
        }
        else{
            for(int &v : graph[u]){
                dfs(graph, v, target, ans, temp);
            }
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = n-1;

        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph, 0, target, ans, temp);
        return ans;
    }
};