/*
 * @lc app=leetcode id=2601 lang=cpp
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start
class Solution {
	bitset<1001> sieve;		// 0 - prime, 1 - not prime
public:
	bool primeSubOperation(vector<int>& nums) {
		// generate prime table
		sieve.set(1);
		for (int i = 2; pow(i, 2) <= 1000; i++)
			if (!sieve.test(i))
				for (int j = pow(i, 2); j <= 1000; j += i)
					sieve.set(j);

		int prev = 1, index = 0;
		while (index < nums.size()) {
			if (prev > nums[index]) return false;

			// if (nums[index] - prev) is prime, just substract it
			if (!sieve.test(nums[index] - prev)) index++;

			// or try next
			prev++;
		}

		return true;
	}
};
// @lc code=end
