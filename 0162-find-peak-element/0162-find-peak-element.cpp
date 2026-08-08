class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ele = INT_MIN;
        int index;
        for(int i =0;i<n;i++){
            if(nums[i]>ele){
                ele  = nums[i];
                index = i;
            }
        }
        return index;
    }
};