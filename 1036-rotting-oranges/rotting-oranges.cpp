class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        int ora = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j},0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) ora++;
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int t = 0;

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            t = max(time, t);
            q.pop();

            

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 1 && vis[nx][ny] == 0){
                    vis[nx][ny] = 2;
                    q.push({{nx,ny}, time+1});
                    ora--;
                }
            }
        }

        if(ora > 0) return -1;
        else return t;
        
    }
};