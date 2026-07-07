class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0, sum = 0, pow10 = 1;
        while(n > 0)
        {
            int res = n % 10;
            sum = sum + res;
            if(res) 
            {
                num = num + res * pow10;
                pow10 *= 10;
            }
            n /= 10;

        }
        return (num * sum * 1ll);
    }

};