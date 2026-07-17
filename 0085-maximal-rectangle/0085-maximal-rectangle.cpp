class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
      int maxi = 0;
      stack<int> st;
      int n = heights.size();
      for(int i =0;i<n;i++){
        while(st.empty()!=true && heights[st.top()]>heights[i]){
            int ele = heights[st.top()];
            st.pop();
            int nse = i;
            int pse = st.empty()? -1:st.top();
            maxi = max(maxi,ele*(nse-pse-1));
        }
        st.push(i);
      }  
      while(st.empty()!=true){
        int ele = heights[st.top()];
        st.pop(); 
        int nse = n;
        int pse = st.empty()? -1:st.top();
        maxi = max(maxi,ele*(nse-pse-1));
      }
      return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans(m,0);
        int maxi = 0;
        
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    ans[j] = ans[j]+1;
                }
                else ans[j]=0;
            }
             int res = largestRectangleArea(ans);
            maxi = max(res,maxi);
        }
        return maxi;
    }
};