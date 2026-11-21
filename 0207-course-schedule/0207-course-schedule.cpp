class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      int n = prerequisites.size();
      vector<vector<int>> adjlist(numCourses);
      vector<int> indegree(numCourses);
      for(int i = 0;i<n;i++){
             int u = prerequisites[i][0];
             int v = prerequisites[i][1];

            adjlist[v].push_back(u);
            indegree[u]++;
        }
       
      queue<int> q;
      vector<int> ans;
      for(int i = 0;i<indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
        }
      }

      while(q.empty()!=true){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adjlist[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
      }
      if(ans.size() == numCourses){
        return true;
      }

      return false;
    }
};