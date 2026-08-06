class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = 0;
        int left = 0;
        int right = 0;
        vector<int> temp;
        while(left<nums1.size() && right<nums2.size()){
            if(nums1[left]<nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
             else{
                temp.push_back(nums2[right]);
                right++;
            }
        }
        while(left<nums1.size()){
            temp.push_back(nums1[left]);
                left++;
        }
        while(right<nums2.size()){
            temp.push_back(nums2[right]);
                right++;
        }
        for(int i = 0 ;i<temp.size();i++){
            sum = sum + temp[i];
        }
        int n = temp.size();
        if(n%2 != 0){
            return temp[n/2];
        }
        else return (double)(temp[(n/2)-1]+temp[(n/2)])/2;
    }
};