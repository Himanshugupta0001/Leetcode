class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];

        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        dist[k] = 0;

        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int node = it.second;

            if(t > dist[node]) continue;

            for(auto it : adj[node]){
                int dn = it.first;
                int ti = it.second;

                if(t+ti < dist[dn]){
                    dist[dn] = t+ti;
                    pq.push({dist[dn], dn});
                }
            }
        }
        int maxTime = *max_element(dist.begin()+1, dist.end());
        if(maxTime == 1e9) return -1;
        else return maxTime;
    }
};