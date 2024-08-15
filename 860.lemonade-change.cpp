/*
 * @lc app=leetcode id=860 lang=cpp
 * @lcpr version=30204
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int bill_5 = 0, bill_10 = 0;
		for (const auto& b : bills) {
			switch (b) {
				case 5 :
					bill_5++;
					break;
				case 10 :
					if (bill_5 < 1) return false;
					bill_5--;
					bill_10++;
					break;
				case 20 :
					if (bill_10 > 0) {
						if (bill_5 < 1) return false;
						bill_10--;
						bill_5--;
					} else {
						if (bill_5 < 3) return false;
						bill_5 -= 3;
					}
					break;
			}
		}
		return true;
	}
};
// @lc code=end
