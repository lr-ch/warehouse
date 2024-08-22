/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
	int findComplement(int num) {
		bitset<32> bs(num);

		bool firstOne = false;
		string bstr = bs.to_string();
		for (auto& ch : bstr) {
			if (ch == '1' && !firstOne) firstOne = true;
			if (firstOne)
				ch = (ch == '0' ? '1' : '0');
		}

		return bitset<32>(bstr).to_ulong();
	}
};
// @lc code=end
