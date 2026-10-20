class Solution {
public:
    bool isHappy(int n) {
        vector<int> hash(1001, -1);

        while (true) {
            if (hash[n] == 1)
                return false;
            
            hash[n] = 1;
            
            int sum = 0;
            while (n != 0) {
                int rem = n % 10;
                sum += rem * rem;
                n /= 10;
            }
            
            if (sum == 1)
                return true;

            n = sum;
        }
    }
};