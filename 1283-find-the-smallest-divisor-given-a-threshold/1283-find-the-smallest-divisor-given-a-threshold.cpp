class Solution {
public:

            
           
        int maximum(vector<int> &nums){
            int maxi = INT_MIN;
            for(int i = 0;i<nums.size();i++){
                if(nums[i]>maxi){
                    maxi = nums[i] ;
                }
            }
            return maxi;
        }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans;
        int high = maximum(nums);
        int low = 1;
        
        while(low<=high){
            long long sum = 0;
            int mid = (low+high)/2;
            for(int i =0;i<n;i++){
                sum = sum+ ceil( (double)nums[i]/(double)mid);
            }
            if(sum<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;

    }
};