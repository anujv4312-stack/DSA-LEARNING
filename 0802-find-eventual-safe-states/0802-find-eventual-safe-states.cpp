class Solution {
public: 
    bool dfs(int node, vector<int> &vis,vector<int> &vischeck,vector<int> &v,vector<vector<int>>& graph){
        vis[node] = 1;
        vischeck[node] = 1;

        for(auto it: graph[node]){
            if(vis[it]!= 1 && vischeck[it]!=1){
                   if(dfs(it,vis,vischeck,v,graph) == true){
                    v[it] = 0;
                    return true;
                   }
            }
            else if(vis[it] == 1 && vischeck[it]== 1){
                  return true;
            }
        }
        vischeck[node] = 0;
        v[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> vis(n,0);
      vector<int> vischeck(n,0);
      vector<int> v(n,0);
      vector<int> ans;

      for(int i = 0;i<n;i++){
        if(vis[i]!=1){
            dfs(i,vis,vischeck,v,graph);
        }
      }
      for(int i = 0;i<v.size();i++){
        if(v[i] != 0){
            ans.push_back(i);
        }
      }
      return ans;  
    }
};