class Solution {
public:
vector<int> findnse(vector<int> &arr){
    int n = arr.size();
    vector<int>nse(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(st.empty()!=true && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()== true){
            nse[i] = n;
        }
        else{
            nse[i] = st.top();
        }
        st.push(i);
    }
return nse;
}
vector<int> findpsee(vector<int> &arr){
    int n = arr.size();
    vector<int> psee(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(st.empty()!=true && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()== true){
            psee[i] = -1;
        }
        else{
            psee[i] = st.top();
        }
        st.push(i);
    }
return psee;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
       int mod = 1e9+7;
       long long total = 0;
       vector<int> nse = findnse(arr);
       vector<int> psee = findpsee(arr);
       for(int i = 0;i<n;i++){
        int right = nse[i]-i;
        int left = i-psee[i];
       total = (total+(right*left %mod)*1LL*arr[i])%mod;
       } 
       return (int)total;
    }
};