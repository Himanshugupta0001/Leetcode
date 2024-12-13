class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];

        vector<int> vi(V, 0);

        for(int i=0; i<V; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                vi[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(vi[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                vi[it]--;
                if(vi[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};