class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     int n = fruits.size();
      map<int,int> mpp;
      int l = 0;
      int r = 0;
      int type = 0;
      int maxlen = 0;
      while(r<n){
        if(mpp.find(fruits[r])==mpp.end()){
           type++;
        }
        mpp[fruits[r]]++;
        if(type>2){
            
         mpp[fruits[l]]--;
         
            if(mpp[fruits[l]] == 0){
              type--;
              mpp.erase(fruits[l]);
            }
            l++;
        }
        if(type<=2){
            maxlen = max(maxlen,(r-l+1));
        }
        r++;
      } 
      return maxlen;
    }
};