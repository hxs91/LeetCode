class Solution {
public:
    double Pow(double x,int n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        double a = Pow(x,n/2);
        if(n%2==0) return a*a;
        else return a*a*x;
    }
    
    double pow(double x, int n) {
        double ans;
        if(n<0){
            ans = Pow(x,-n);
            return 1/ans;
        }
        else{
            return Pow(x,n);
        }
    }
};