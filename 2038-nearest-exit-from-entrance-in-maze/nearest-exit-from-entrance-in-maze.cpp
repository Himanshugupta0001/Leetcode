class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int cnt = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int, int> temp = q.front();
                q.pop();

                int i = temp.first;
                int j = temp.second;

                if((temp != make_pair(entrance[0], entrance[1])) && (i == 0 || i == m-1 || j == 0 || j == n-1)){
                    return cnt;
                }

                for(auto &dir : directions){
                    int newr = i + dir[0];
                    int newc = j + dir[1];

                    if(newr >= 0 && newr < m && newc >= 0 && newc < n && maze[newr][newc] != '+'){
                        q.push({newr, newc});
                        maze[newr][newc] = '+';
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};