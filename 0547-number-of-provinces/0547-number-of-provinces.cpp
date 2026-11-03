class Solution {
public:
    void dfs(int node,vector<vector<int>> &list,vector<int> &vis){
        vis[node] = 1;
        for(auto it :list[node]){
            if(vis[it]!=1){
                dfs(it,list,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjls(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        vector<int> vis(n);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};