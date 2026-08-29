class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even = 0;
        for(int i = 0 ; i<nums.size();i++){
                    int cnt = 0;
                    int n = nums[i];
                    while(n!=0){
                        cnt++;
                        n = n/10;
                    }
                    if(cnt%2 == 0){
                        even++;
                    }
        }
        return even;
    }
};