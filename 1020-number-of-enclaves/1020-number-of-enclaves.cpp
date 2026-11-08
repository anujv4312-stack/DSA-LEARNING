class Solution {
public:
     void dfs(int row,int col,vector<vector<int>> &vis,queue<pair<int,int>> &q,vector<vector<int>>& grid,int r,int c,int &cnt){
        vis[row][col] = 1;
        cnt++;
        q.push({row,col});
        while(q.empty()!=true){
            pair<int,int> ele = q.front();
            q.pop();
            int ro = ele.first;
            int cm = ele.second;
            if( (ro-1>=0 && ro-1<r) && (cm>=0 && cm<c) && grid[ro-1][cm] == 1 && vis[ro-1][cm]!=1){
                cnt++;
                vis[ro-1][cm] = 1;
                q.push({ro-1,cm});
            }

            if((ro>=0 && ro<r) && (cm+1>=0 && cm+1<c) && grid[ro][cm+1] == 1  &&  vis[ro][cm+1]!=1){
                cnt++;
                vis[ro][cm+1] = 1;
                q.push({ro,cm+1});
            }
             if((ro+1>=0 && ro+1<r) && (cm>=0 && cm<c) && grid[ro+1][cm] == 1  &&  vis[ro+1][cm]!=1){
                cnt++;
                vis[ro+1][cm] = 1;
                q.push({ro+1,cm});
            }
            
            if((ro>=0 && ro<r) && (cm-1>=0 && cm-1<c) && grid[ro][cm-1] == 1  && vis[ro][cm-1]!=1){
                cnt++;
                vis[ro][cm-1] = 1;
                q.push({ro,cm-1});
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        queue<pair<int,int>> q;
        for(int i = 0;i<c;i++){
            if(grid[0][i]==1 && vis[0][i]!=1){
                dfs(0,i,vis,q,grid,r,c,cnt);
            }
            if(grid[r-1][i]==1 && vis[r-1][i]!=1){
                dfs(r-1,i,vis,q,grid,r,c,cnt);
            }

        }
        for(int i = 0;i<r;i++){
            if(grid[i][0]==1 && vis[i][0]!=1){
                dfs(i,0,vis,q,grid,r,c,cnt);
            }
            if(grid[i][c-1]==1 && vis[i][c-1]!=1){
                dfs(i,c-1,vis,q,grid,r,c,cnt);
            }

        }
        int counter = 0;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==1){
                    counter++;
                }
            }
        }
        return counter-cnt;
    }
};