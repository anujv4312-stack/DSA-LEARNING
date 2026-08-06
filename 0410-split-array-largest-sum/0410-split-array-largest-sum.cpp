class Solution {
public:
int maximum(vector<int> &nums){
    int maxi= INT_MIN;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]>maxi){
            maxi = nums[i];
        }
    }
    return maxi;
}

int sum(vector<int> &nums){
    int add= 0;
    for(int i = 0;i<nums.size();i++){
        add= add+nums[i];
    }
    return add;
}
 bool canwesum(vector<int> &nums,int mid,int k){
    int noofele = 1;
    int sum = 0;
    for(int i =0;i<nums.size();i++){
        if(sum+nums[i]<=mid){
            sum = sum+nums[i];
        }
        else{
            noofele = noofele+1;
            sum = nums[i];
        }
    }
    if(noofele<=k){
        return true;
    }
    else return false;
 }
    int splitArray(vector<int>& nums, int k) {
        int low = maximum(nums);
        int high = sum(nums);
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            if(canwesum(nums,mid,k)== true){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
        }
    
};