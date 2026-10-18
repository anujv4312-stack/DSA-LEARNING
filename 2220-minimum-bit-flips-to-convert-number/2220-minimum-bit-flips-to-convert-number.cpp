class Solution {
public:
    int countbits( int ans,int cnt){
        while(ans!=0){
            if((ans&1) ==1 ){
             cnt++;
            }
            ans = ans>>1;
        }
        return cnt;
    }
    int minBitFlips(int start, int goal) {
       int ans = (start^goal);
      return countbits(ans,0);
    }
};