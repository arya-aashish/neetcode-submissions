class Solution {
public:
    double mypow(double x, int n){
        if (n==0)
            return 1;

        double half= mypow(x, n/2);

        if (n%2==0)
            return half*half;
        else
            return x*half*half;

}
    double myPow(double x, int n) {
        if(n>=0)
            return mypow(x,n);
        else
            return 1/mypow(x,n);
    }
};
