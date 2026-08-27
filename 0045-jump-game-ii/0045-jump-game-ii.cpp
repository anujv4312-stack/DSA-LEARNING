class Solution {
public:
    int jump(vector<int>& nums) {
      int i = 0;
      int maxi = 0;
      int cnt = 0;
      int range = 0;
      while(i<nums.size()-1){
        maxi = max(maxi,i+nums[i]);
        if(i == range){
            cnt++;
            range = maxi;
        }
         i++;
      }  
      return cnt;   
    }
};