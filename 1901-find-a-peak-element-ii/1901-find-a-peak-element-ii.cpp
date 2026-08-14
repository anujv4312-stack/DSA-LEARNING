class Solution {
public:
int findmaxrow(vector<vector<int>>& matrix,int n,int mid){
    int maxi = INT_MIN;
    int index;
    for(int i =0;i<n;i++){
        if(matrix[i][mid]>maxi){
            maxi = matrix[i][mid];
            index = i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
      int n = matrix.size();  
      int m = matrix[0].size();
      int low = 0;
      int high = m-1;
      
      while(low<=high){
        int mid = (low+high)/2;
        int mr = findmaxrow(matrix,n,mid);
        int left = (mid-1>=0)? matrix[mr][mid-1]:-1;
        int right =(mid+1<m)? matrix[mr][mid+1]:-1;
        if(matrix[mr][mid]>left && matrix[mr][mid]>right){
            return {mr,mid};
        }
        if(matrix[mr][mid]<left){
            high = mid-1;
        }
        else low = mid+1;
      }
      return {-1,-1};
    }
};