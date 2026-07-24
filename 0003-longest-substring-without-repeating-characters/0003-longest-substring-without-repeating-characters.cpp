class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        map<int ,int> mpp;
        int l = 0;
        int r = 0;
        int n = s.size();
        while(r<n){
             if (mpp.find(s[r])!=mpp.end()){
                l = max(l,mpp[s[r]]+1);
            }
            mpp[s[r]] = r;
            maxlen = max(maxlen,(r-l+1));
            r++;
        }
        return maxlen;
    }
};