class Solution {
public:
    vector<vector<int>> dfs(int row,int col,int color,vector<vector<int>>& grid,int r,int c,vector<vector<int>> &vis,queue<pair<int,int>> &q,int inicolor){
        vis[row][col] = 1;
        grid[row][col] = color;
        q.push({row,col});
        while(q.empty()!=true){
            pair<int,int> ele = q.front();
            q.pop();
            int ro = ele.first;
            int cm = ele.second;
            if( (ro-1>=0 && ro-1<r) && (cm>=0 && cm<c) && grid[ro-1][cm] == inicolor && vis[ro-1][cm]!=1){
                vis[ro-1][cm] = 1;
                grid[ro-1][cm] = color;
                q.push({ro-1,cm});
            }

            if((ro>=0 && ro<r) && (cm+1>=0 && cm+1<c) && grid[ro][cm+1] == inicolor  &&  vis[ro][cm+1]!=1){
                vis[ro][cm+1] = 1;
                grid[ro][cm+1] = color;
                q.push({ro,cm+1});
            }
             if((ro+1>=0 && ro+1<r) && (cm>=0 && cm<c) && grid[ro+1][cm] == inicolor  &&  vis[ro+1][cm]!=1){
                vis[ro+1][cm] = 1;
                grid[ro+1][cm] = color;
                q.push({ro+1,cm});
            }
            
            if((ro>=0 && ro<r) && (cm-1>=0 && cm-1<c) && grid[ro][cm-1] == inicolor  && vis[ro][cm-1]!=1){
                vis[ro][cm-1] = 1;
                grid[ro][cm-1] = color;
                q.push({ro,cm-1});
            }
        }
        return grid;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        queue<pair<int,int>> q;
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = dfs(sr,sc,color,image,r,c,vis,q,inicolor);
        return ans;
    }
};