class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {\
        int cntfive = 0;
        int cnten = 0;
        for(int i = 0;i<bills.size();i++){
                 if(bills[i]==5){
                    cntfive++;
                 }
                 else if(bills[i] == 10){
                    if(cntfive!=0){
                        cntfive--;
                        cnten++;
                    }
                    else return false;
                 }
                 else if(bills[i] == 20){
                    if(cntfive >=1 && cnten >= 1){
                        cntfive--;
                        cnten--;
                    }
                    else if(cntfive >=3){
                        cntfive = cntfive-3;
                    }
                    else return false;
                 }
        }
        return true;
    }
};