class Solution {
public:
    int arrangeCoins(int n) {
        long x = sqrt(2*( long)n);
        long long sum = x*(x+1)/2;
        if(sum>n){
            return x-1;
        }
        return x;
    }
};