class Solution {
public:
    bool topologicalSort(int V, vector<vector<int>>& prerequisities) {
        // Your code here
        vector<int> adj[V];
        for(auto it : prerequisities){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vi(V);
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                vi[it]++;
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
                if(vi[it] ==  0){
                    q.push(it);
                }
            }
        }

        if(ans.size() == V) return true;
        else return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return topologicalSort(numCourses, prerequisites);
    }
};