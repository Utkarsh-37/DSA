class Solution {
public:
    const long long mod = 1e9 + 7;
    long long modPower(long long base, long long exponent)
    {
        if(exponent == 0)
            return 1;
        
        long long half = modPower(base, exponent/2);
        long long result = (half * half) % mod;

        if(exponent % 2 == 1)
            result = (result * base) % mod;
        
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n+1)/2;
        long long oddPos = n/2;

        long long part1 = modPower(5, evenPos); // 5 as we have 5 choices for even 2,4,6,8,0
        long long part2 = modPower(4, oddPos);  // 4 as we have 4 choices for primes 2,3,5,7

        return (part1*part2)%mod;
    }
};