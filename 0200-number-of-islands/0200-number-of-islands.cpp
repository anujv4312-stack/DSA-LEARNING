class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid,queue<pair<int,int>> &q,int r,int c){
        vis[row][col] = 1;
        q.push({row,col});
        while(q.empty()!=true){
            pair<int,int> ele = q.front();
            q.pop();
            int ro = ele.first;
            int cm = ele.second;
            if( (ro-1>=0 && ro-1<r) && (cm>=0 && cm<c) && grid[ro-1][cm] == '1' && vis[ro-1][cm]!=1){
                vis[ro-1][cm] = 1;
                q.push({ro-1,cm});
            }

            if((ro>=0 && ro<r) && (cm+1>=0 && cm+1<c) && grid[ro][cm+1] == '1' &&  vis[ro][cm+1]!=1){
                vis[ro][cm+1] = 1;
                q.push({ro,cm+1});
            }
             if((ro+1>=0 && ro+1<r) && (cm>=0 && cm<c) && grid[ro+1][cm] == '1' &&  vis[ro+1][cm]!=1){
                vis[ro+1][cm] = 1;
                q.push({ro+1,cm});
            }
            
            if((ro>=0 && ro<r) && (cm-1>=0 && cm-1<c) && grid[ro][cm-1] == '1' && vis[ro][cm-1]!=1){
                vis[ro][cm-1] = 1;
                q.push({ro,cm-1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int cnt = 0;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(vis[i][j]!=1 && grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,vis,grid,q,r,c);
                }
            }
        }
        return cnt;
    }
};