class Solution {
public:
   vector<int> findnse(vector<int>& heights){
    stack<int> st;
    int n = heights.size();
    vector<int> nse(n);
    for(int i =n-1;i>=0;i--){
        while(st.empty()!=true&&heights[st.top()]>=heights[i]){
            st.pop();
        }
        
        if(st.empty()){
            nse[i] = n;
        }
        else{
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
   }
   vector<int> findpse(vector<int>& heights){
    stack<int> st;
    int n = heights.size();
    vector<int> pse(n);
    for(int i =0;i<n;i++){
        while(st.empty()!=true&&heights[st.top()]>=heights[i]){
            st.pop();
        }
        
        if(st.empty()){
            pse[i] = -1;
        }
        else{
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
   }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findnse(heights);
        vector<int> pse = findpse(heights);
        int maxi = 0;
        for(int i =0;i<heights.size();i++){
           maxi = max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};