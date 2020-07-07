#include "iostream"
using namespace std;

class Solution {
public:
    long  power(int x,int n){
        if(n == 0)
            return 1;
        return (power(x,--n)*x)%1000000007;
    }
    int cuttingRope(int n) {
        if(n <= 3)
            return 2;
        else if(n == 4)
            return 4;
        else if(n == 5)
            return 6;
        int divisor = n/3;
        int remainder = n%3;
        if(remainder == 1)
            return power(3,divisor-1)*(3+remainder);
        else if(remainder == 2)
            return power(3,divisor)*remainder;
        else 
            return power(3,divisor);
    }
};


int main(void){
    Solution solution;
    cout << solution.cuttingRope(10) << endl;
    return 0;
}