class Solution {
public:
    string minWindow(string s, string t) {
      int n = s.size();
      int m = t.size();
      int cnt = 0;
      int stind = -1;
      int minlen = INT_MAX;
      int l = 0;
      int r = 0;
      unordered_map<char,int> mpp;
      for(auto it : t){
        mpp[it]++;
      }
      while(r<n){
        if(mpp[s[r]]>0){
            cnt++;
        }
        mpp[s[r]]--;
        while(cnt == m){
            if((r-l+1)<minlen){
                minlen = (r-l+1);
                stind = l;
            }
            mpp[s[l]]++;
            if(mpp[s[l]]>0) cnt--;
            l++;
        }
        r++;
      }  
      return stind == -1 ? "":s.substr(stind,minlen);
    }
};