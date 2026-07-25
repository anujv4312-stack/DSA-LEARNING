class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      vector<int> temp;
      int cnt=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]==1){
            cnt++;
        }
        else{
            temp.push_back(cnt);
            cnt=0;
        }
      } 
      temp.push_back(cnt);
      int maxi=INT_MIN; 
      for(int i=0;i<temp.size();i++){
        if(temp[i]>maxi){
            maxi=temp[i];
        }
      } 
      return maxi;
    }
};