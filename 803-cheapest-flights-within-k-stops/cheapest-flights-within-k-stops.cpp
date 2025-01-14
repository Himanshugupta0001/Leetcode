class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int ru = it.second.second;

            if(stop > k) continue;

            for(auto it : adj[node]){
                int no = it.first;
                int c = it.second;

                if(ru+c < dist[no] && stop <= k){
                    dist[no] = ru+c;
                    q.push({stop+1, {no, ru+c}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};