class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            bool flag = false;
            for(int j = i+1;j<=i+(nums.size()-1);j++){
                int ind = j%nums.size();
                if(nums[ind]>nums[i]){
                    ans.push_back(nums[ind]);
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};