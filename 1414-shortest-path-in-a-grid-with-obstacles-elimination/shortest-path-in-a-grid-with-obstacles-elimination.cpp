class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> q;

        q.push({0, 0, k});
        bool visited[41][41][1601];
        memset(visited, false, sizeof(visited));

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                vector<int> temp = q.front();
                q.pop();

                int x = temp[0];
                int y = temp[1];
                int obs = temp[2];

                if(x == m-1 && y == n-1){
                    return steps;
                }

                for(int i=0; i<4; i++){
                    int newx = x + dx[i];
                    int newy = y + dy[i];

                    if(newx < 0 || newx >= m || newy < 0 || newy >= n){
                        continue;
                    }

                    if(grid[newx][newy] == 0 && !visited[newx][newy][obs]){
                        q.push({newx, newy, obs});
                        visited[newx][newy][obs] = true;
                    }
                    else if(grid[newx][newy] == 1 && obs > 0 && !visited[newx][newy][obs-1]){
                        q.push({newx, newy, obs-1});
                        visited[newx][newy][obs-1] = true;
                    }
                } 
            }
            steps++;
        }
        return -1;
    }
};