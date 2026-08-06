class Solution {
public:
  int maximum(vector<int> &weights){
            int maxi = INT_MIN;
            for(int i = 0;i<weights.size();i++){
                if(weights[i]>maxi){
                    maxi = weights[i] ;
                }
            }
            return maxi;
        }
int sum(vector<int> &weights){
    int sum = 0;
    for(int i = 0;i<weights.size();i++){
        sum = sum+weights[i];
    }
    return sum;
}
int numday(vector<int>& weights, int capacity){
    int load = 0;
    int dayss = 1;
    for(int i = 0;i<weights.size();i++){
        if(load+weights[i]>capacity){
            dayss = dayss +1;
            load = weights[i];
        }
        else{
            load = load+weights[i];
        }
    }
    return dayss;
}
    int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int low = maximum(weights);
    int high = sum(weights); 
    int ans;
    while(low<=high){
        int mid = (low+high)/2;
        int noOfDays = numday(weights,mid);
        if(noOfDays<= days){
          ans = mid;
          high = mid -1;
        }
        else{
            low = mid+1;
        }
    }  
    return ans; 
    }
};