class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0;
        int r = n-1;
        int leftmax = 0;
        int rightmax = 0;
        while(l<r){
            leftmax = max(leftmax,height[l]);
            rightmax = max(rightmax,height[r]);
            if(leftmax<rightmax){
                ans = ans+(leftmax-height[l]);
                l++;
            }
            else {
                ans = ans+(rightmax-height[r]);
                r--;
            }
        }
        return ans;
    }
};