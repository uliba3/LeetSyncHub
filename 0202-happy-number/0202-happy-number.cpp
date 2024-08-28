class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while(n!=0) {
            sum += ((n%10)*(n%10));
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<int, bool> m;
        while(!m[n]){
            m[n] = true;
            n = getSum(n);
        }
        return n==1;
    }
};