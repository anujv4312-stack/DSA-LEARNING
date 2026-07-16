class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
       for(int i =0;i<num.size();i++){
        while(st.empty()!=true && k>0 && st.top()-'0'>num[i]-'0'){
            st.pop();
            k--;
        }
        st.push(num[i]);
       } 
        while(k>0){
        st.pop();
        k--;
        }
        if(st.empty()==true){
            return "0";
        }
        string ans = "";
        while(st.empty()!=true){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i<ans.size()&& ans[i]=='0'){
            i++;
        }
        ans = ans.substr(i);
        if(ans.size()==0){
            return "0";
        }
             return ans;
            }
};