class Solution {
public:
    void dfs(queue<pair<int,int>> &q,int r,int c,int &minutes,vector<vector<int>> &grid){
        while(q.empty()!=true){
           
            int n = q.size();
            for(int i = 0;i<n;i++){
            pair<int,int> ele = q.front();
            int ro = ele.first;
            int cm = ele.second;
            q.pop();
                if((ro-1>=0 && ro-1<r) && (cm>=0 && cm < c) && grid[ro-1][cm] == 1){
                    q.push({ro-1,cm});
                    grid[ro-1][cm] = 2;
                }
                if((ro>=0 && ro<r) && (cm+1>=0 && cm+1 < c) && grid[ro][cm+1] == 1){
                    q.push({ro,cm+1});
                    grid[ro][cm+1] = 2;
                }
                 if((ro+1>=0 && ro+1<r) && (cm>=0 && cm < c) && grid[ro+1][cm] == 1){
                    q.push({ro+1,cm});
                    grid[ro+1][cm] = 2;
                }
                 if((ro>=0 && ro<r) && (cm-1>=0 && cm-1 < c) &&  grid[ro][cm-1] == 1){
                    q.push({ro,cm-1});
                    grid[ro][cm-1] = 2;
                }
            }
            if(q.size() != 0){
                minutes++;
            } 
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        int minutes = 0;
        for(int i = 0 ;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        dfs(q,r,c,minutes,grid);
        for(int i = 0 ;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minutes;
    }
};