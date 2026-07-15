class Solution {
public:
    vector<int> findnge(vector<int> &arr){
    int n = arr.size();
    vector<int>nge(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(st.empty()!=true && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()== true){
            nge[i] = n;
        }
        else{
            nge[i] = st.top();
        }
        st.push(i);
    }
return nge;
}

vector<int> findpgee(vector<int> &arr){
    int n = arr.size();
    vector<int> pgee(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(st.empty()!=true && arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty()== true){
            pgee[i] = -1;
        }
        else{
            pgee[i] = st.top();
        }
        st.push(i);
    }
return pgee;
}
long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
       
       long long totall = 0;
       vector<int> nge = findnge(arr);
       vector<int> pgee = findpgee(arr);
       for(int i = 0;i<n;i++){
        int right = nge[i]-i;
        int left = i-pgee[i];
       totall = (totall+(right*left)*1LL*arr[i]);
       } 
       return totall;
}
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
long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
       int mod = 1e9+7;
       long long total = 0;
       vector<int> nse = findnse(arr);
       vector<int> psee = findpsee(arr);
       for(int i = 0;i<n;i++){
        int right = nse[i]-i;
        int left = i-psee[i];
       total = (total+(right*left)*1LL*arr[i]);
       } 
       return total;
}
    long long subArrayRanges(vector<int>& nums) {
        long long maximum = sumSubarrayMaxs(nums);
    long long minimum = sumSubarrayMins(nums);

    return maximum - minimum;
    }
};