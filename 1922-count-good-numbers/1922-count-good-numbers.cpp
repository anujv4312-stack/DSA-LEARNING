class Solution {
public:
long long M = 1e9+7;
    long long pow(long long a,long long b){
        if(b==0) return 1;
        if(b%2==0){
            return pow((a*a)%M,b/2)%M;
        }
        else return (a*pow(a,b-1)%M)%M;
    }
    int countGoodNumbers(long long n) {
      long long even = (n+1)/2;
      long long odd = n/2;
      long long result = (pow(5,even)*pow(4,odd))%M;
      return (int)result;
    }
    
};