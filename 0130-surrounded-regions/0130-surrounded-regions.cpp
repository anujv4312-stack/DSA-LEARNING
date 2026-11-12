class Solution {
public:
    void dfs(int ro,int co,queue<pair<int,int>> &q,vector<vector<char>>& board,int n,int m){
        q.push({ro,co});
        board[ro][co] = '#';
        int nrow [] = {-1,0,1,0};
        int ncol[] = {0,1,0,-1};
        while(q.empty()!=true){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0;i<4;i++){
                int nr = r+nrow[i];
                int nc = c+ncol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc] == 'O' ){
                    q.push({nr,nc});
                    board[nr][nc] = '#';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        
        for(int i = 0;i<m;i++){
            if(board[0][i] == 'O'){
                dfs(0,i,q,board,n,m);
            }

            if(board[n-1][i] == 'O'){
                dfs(n-1,i,q,board,n,m);
            }
        }

        for(int i = 0;i<n;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,q,board,n,m);
            }

            if(board[i][m-1] == 'O'){
                dfs(i,m-1,q,board,n,m);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};