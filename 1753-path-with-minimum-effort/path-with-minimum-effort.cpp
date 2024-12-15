class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
               greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dif = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == n-1 && y == m-1) return dif;

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int ef = max(abs(heights[x][y] - heights[nx][ny]), dif);

                    if(ef < dist[nx][ny]){
                        dist[nx][ny] = ef;
                        pq.push({ef, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};