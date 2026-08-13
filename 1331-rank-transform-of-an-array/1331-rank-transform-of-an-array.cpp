class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        unordered_map<int,int> mpp;
        sort(arr.begin(),arr.end());
        int rank = 1;
        for(int i = 0;i<arr.size();i++){
            if(mpp.find(arr[i])==mpp.end()){
           mpp[arr[i]] = rank;
           rank++;
        }
        }
        for(int i = 0;i<arr.size();i++){
            nums[i] = mpp[nums[i]];
        }

        return nums;
    }
};