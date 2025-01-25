class Solution {
public:
    void dfs(vector<vector<int>>& stones, int ind, vector<bool>& visited){
        visited[ind] = true;

        for(int i=0; i<stones.size(); i++){
            int r = stones[ind][0];
            int c = stones[ind][1];

            if(visited[i] == false && (stones[i][0] == r || stones[i][1] == c)){
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool> visited(n, false);
        int grp = 0;

        for(int i=0; i<n; i++){
            if(visited[i] == true){
                continue;
            }

            dfs(stones, i, visited);
            grp++;
        }
        return (n - grp);
    }
};