class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ac = image[sr][sc];
        int n = image.size();
        int m = image[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis = image;
        vis[sr][sc] = color;

        q.push({{sr, sc}, color});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int co = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = r + dx[i];
                int ny = c + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny] == ac && vis[nx][ny] != color){
                    vis[nx][ny] = color;
                    q.push({{nx, ny}, color});
                }
            }
        }
        return vis;
    }
};