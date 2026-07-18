class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(st.empty()!=true && st.front()<=(i-k)){
                st.pop_front();
            }
            while(st.empty()!=true && nums[i]>=nums[st.back()]){
                st.pop_back();
            }
            st.push_back(i);
            if(i>=(k-1)){
                 ans.push_back(nums[st.front()]);
            }
        }
        return ans;
    }
};