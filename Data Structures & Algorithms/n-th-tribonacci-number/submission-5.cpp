class Solution {
public:
    int tribonacci(int n) {
        vector<int> hash(n + 1, -1);
        return next(n, hash);
    }

    int next(int n, vector<int>& hash) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }

        if (hash[n] != -1) {
            return hash[n];
        }
        
        return hash[n] = next(n - 1, hash) + next(n - 2, hash) + next(n - 3, hash);
    }
};