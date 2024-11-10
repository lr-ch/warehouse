/*
 * @lc app=leetcode id=3097 lang=cpp
 *
 * [3097] Shortest Subarray With OR at Least K II
 */

// @lc code=start
class Solution {
public:
	int minimumSubarrayLength(vector<int>& nums, int k) {
		int ans = INT_MAX, left = 0, right = 0;
		vector<int> bits(32, 0);

		while (right < nums.size()) {
			bitset<32> r(nums[right]);
			for (int i = 0; i < 32; i++) if (r.test(i)) bits[i]++;

			auto bitsToInt = [](const vector<int>& b) -> int {
				bitset<32> res(0);
				for (int i = 0; i < 32; i++) if (b[i]) res.set(i);
				return static_cast<int>(res.to_ulong());
			};

			// try to shrink window
			while (left <= right && bitsToInt(bits) >= k) {
				ans = min(ans, right - left + 1);

				// remove leftmost number from window
				bitset<32> l(nums[left]);
				for (int i = 0; i < 32; i++) if (l.test(i)) bits[i]--;

				left++;
			}

			// increase window
			right++;
		}
		return ans == INT_MAX? -1 : ans;
	}
};
// @lc code=end
