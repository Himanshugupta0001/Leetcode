class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis, int delrow[],int delcol[]){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nr=row+delrow[i];
            int nc=col+delcol[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O' && vis[nr][nc]!=1){
                dfs(nr,nc,board,vis,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && vis[0][i]!=1){
                dfs(0,i,board,vis,delrow,delcol);
            }
            if(board[n-1][i]=='O' && vis[n-1][i]!=1){
                dfs(n-1,i,board,vis,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i][0]!=1){
                dfs(i,0,board,vis,delrow,delcol);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]!=1){
                dfs(i,m-1,board,vis,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};