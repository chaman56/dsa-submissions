class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>>q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        q.push({-1, -1});
        int step = 0;
        while(!q.empty()){
            pair<int, int>cell = q.front();
            int i = cell.first, j = cell.second;
            q.pop();
            if(i==-1){
                if(q.empty())break;
                q.push({-1, -1});
                step++;
                continue;
            }
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j] = 2;
                q.push({i-1, j});
            }
            if(i+1<m && grid[i+1][j]==1){
                grid[i+1][j] = 2;
                q.push({i+1, j});
            }
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1] = 2;
                q.push({i, j-1});
            }
            if(j+1<n && grid[i][j+1]==1){
                grid[i][j+1] = 2;
                q.push({i, j+1});
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return step;
    }
};
