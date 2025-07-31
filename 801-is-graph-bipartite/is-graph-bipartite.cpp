// class Solution {
// public:
//     bool check(int start, vector<int> &color, vector<vector<int>> &graph, int ini){
//         queue<int> q;
//         q.push(start);
//         color[start] = ini;

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();

//             for(auto &it : graph[node]){
//                 if(color[it] == color[node]){
//                     return false;
//                 }
//                 else if(color[it] == -1){
//                     color[it] = 1-color[node];
//                     q.push(it);
//                 }
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<int> color(V, -1);
//         for(int i=0; i<V; i++){
//             if(!color[i]){
//                 if(check(i, color, graph, 0) == false){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        
        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};