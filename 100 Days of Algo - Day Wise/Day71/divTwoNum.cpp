class Solution {
public:
    long long div(long long dividend, long long divisor) {
        if(dividend < divisor) return 0;
        long long t = divisor;
        while(t << 1 < dividend) {
            t <<= 1;
        }
        return t / divisor;
    }
    
    int divide(long long dividend, long long divisor) {
        long long q = 1;
        long long ans = 0;
        int p = -1;
        if(dividend > 0 && divisor > 0) p = 1;
        if(dividend < 0 && divisor < 0) p = 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while(q > 0) {
            q = div(dividend, divisor);
            dividend -= (q * divisor);
            ans += q;
        }
        if(p == -1) ans = -ans;
        if(ans < pow(-2, 31) || ans > (pow(2, 31) - 1)) ans = pow(2, 31) - 1;
        return ans;
    }
};