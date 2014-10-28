class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size(),adt,i;
        digits[len-1]=(digits[len-1]+1)%10;
        if(digits[len-1] == 0) adt = 1;
        else return digits;
        i = len-2;
        while(adt && i>=0){
            digits[i] = (digits[i]+adt)%10;
            if(digits[i] == 0) adt = 1;
            else adt = 0;
            i--;
        }
        if(adt){
            digits.push_back(0);
            for(i=len-1;i>=0;i--) digits[i+1]=digits[i];
            digits[0]=1;
        }
        return digits;
    }
};