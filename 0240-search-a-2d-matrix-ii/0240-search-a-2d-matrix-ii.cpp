class Solution {
public:
    int binarysearch(vector<int> &arr,int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]== target){
                return arr[mid];
            }
            if(arr[mid]>=target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -12;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i =0;i<n;i++){
            int x = binarysearch(matrix[i],target);
            if(x == target){
                return true;
            }
        }
        return false;
    } 
};