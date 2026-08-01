class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3] = {-1,-1,-1};
        int count = 0;
        for(int i =0;i<s.size();i++){
              hash[s[i]-'a'] = i;
              count = count+(1+min({hash[0],hash[1],hash[2]}));
        }
        return count;
    }
};