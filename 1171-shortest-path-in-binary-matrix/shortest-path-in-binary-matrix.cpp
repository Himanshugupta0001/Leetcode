class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        if(n==1 && grid[0][0] == 0) return 1;

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && dis+1 < dist[nx][ny]){
                    dist[nx][ny] = dis+1;

                    if(nx == n-1 && ny == n-1) return dis+1;

                    q.push({dis+1, {nx, ny}});
                }
            }
        }
        return -1;
    }
};