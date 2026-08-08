class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int low =0;
        int high = n-1;
        int mid;
        while(low<high){
             mid = (low+high)/2;
            if(mid % 2 !=0 ) mid--;
            if(arr[mid] == arr[mid+1]){
                low = mid+2;
            }
            else{
                high = mid-1;
            }
        }
        return arr[low];
    }
};