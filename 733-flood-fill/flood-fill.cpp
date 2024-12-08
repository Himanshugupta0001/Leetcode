class Solution {
public:
    void dfs(int sr, int sc, int color, vector<vector<int>> &image, vector<vector<int>> &vis, int n, int m, int ac){
        vis[sr][sc] = color;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nx = sr + dx[i];
            int ny = sc + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny] == ac && vis[nx][ny] != color){
                dfs(nx, ny, color, image, vis, n, m, ac);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ac = image[sr][sc];
        vector<vector<int>> vis = image;

        int n = image.size();
        int m = image[0].size();

        dfs(sr, sc, color, image, vis, n, m, ac);

        return vis;
    }
};