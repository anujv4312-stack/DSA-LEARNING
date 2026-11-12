class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
       int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int nrow [] = {-1,0,1,0};
        int ncol[] = {0,1,0,-1};
        
        while(q.empty()!=true){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            ans[r][c] = steps;
            
            for(int i = 0;i<4;i++){
                int nr = r+nrow[i];
                int nc = c+ncol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] == 0 ){
                    q.push({{nr,nc},steps+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};