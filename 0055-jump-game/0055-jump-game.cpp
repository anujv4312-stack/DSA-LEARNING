class Solution {
public:
    bool canJump(vector<int>& nums) {
     
      int i = 0;
      int maxi = 0;
      if(nums.size() == 1) return true;
      while(i<nums.size()-1){
        if(i > maxi) return false;
          maxi = max(maxi,i+nums[i]);
          if(maxi >= nums.size()-1){
            return true;
          }
         i++;
      }  
      return false;
    }
};