class Solution {
public:
    string getPermutation(int n, int k) {
        // Available numbers
        vector<int> nums;

        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        // factorial[i] = i!
        vector<int> factorial(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        // Convert k from 1-based to 0-based
        --k;

        string ans;

        for (int remaining = n; remaining >= 1; --remaining) {
            // Each possible first number represents
            // (remaining - 1)! permutations.
            int blockSize = factorial[remaining - 1];

            // Which block contains k?
            int index = k / blockSize;

            // Select that number
            ans += to_string(nums[index]);

            // Remove selected number
            nums.erase(nums.begin() + index);

            // Move inside the selected block
            k %= blockSize;
        }

        return ans;
    }
};
