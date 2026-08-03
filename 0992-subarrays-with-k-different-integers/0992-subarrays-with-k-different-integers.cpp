class Solution {
public:
    int count(vector<int>& nums, int k){
    
        int r = 0;
        int l = 0;
        unordered_map<int,int> mpp;
        int n = nums.size();
        int counter = 0;
        while(r<n){
            
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                  l++;
            }
            counter = counter +(r-l+1);
            r++;
        }
         return counter;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return count(nums,k)-count(nums,k-1); 
    }
};