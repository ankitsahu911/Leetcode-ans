class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long absDividend = labs((long long)dividend);
        long long absDivisor = labs((long long)divisor);
        long long result = 0;

        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long count = 1;

            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                count <<= 1;
            }

            absDividend -= tempDivisor;
            result += count;
        }

        return negative ? -result : result;
    }
};