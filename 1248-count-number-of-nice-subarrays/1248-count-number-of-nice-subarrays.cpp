class Solution {
public:
    int counter(vector<int> &nums,int k){
        int r = 0;
      int l = 0;
      int cnt = 0;
      int subcnt = 0;
      int n = nums.size();
      while(r<n){
        if(nums[r]%2 !=0){
            cnt++;
        }
        while(cnt>k){
            if(nums[l]%2 != 0){
                cnt--;
            }
            l++;
        }
        subcnt = subcnt+(r-l+1);
        r++;
      }  
      return subcnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
      return counter(nums,k)-counter(nums,k-1);
    }
};