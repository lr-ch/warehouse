/*
 * @lc app=leetcode id=564 lang=cpp
 *
 * [564] Find the Closest Palindrome
 */

// @lc code=start
class SolutionTLE {
	/*
	 * Time Limit Exceeded
	 *  - 163/217 cases passed (N/A)
	 * Testcase
	 *  - "807045053224792883"
	 * Expected Answer
	 *  - "807045053350540708"
	 */
	bool isPalindrome(const string &s) {
		size_t i1 = 0, i2 = s.length() - 1;
		while (i1 < i2)
			if (s[i1++] != s[i2--]) return false;
		return true;
	}

public:
	string nearestPalindromic(string n) {
		long long up = stoll(n) + 1, down = up - 2;		// n is excluded
		while (!isPalindrome(to_string(up))) up++;
		while (!isPalindrome(to_string(down))) down--;

		return (up - stoll(n) < stoll(n) - down ? to_string(up) : to_string(down));
	}
};

class Solution {
	array<long long, 5> candidates;		// only 5 candidates for 5 cases
public:
	string nearestPalindromic(string n) {
		int N = n.length();
		long long num = stoll(n);

		// case 1. '1' with only '0's followed, the answer is "9..." with one digit less
		// e.g. 100 -> pow(10, 3 - 1) - 1 = 99
		candidates[0] = pow(10, N - 1) - 1;

		// case 2. only '9's, the answer is "1...1" with one more digit
		// e.g. 999 -> pow(10, 3) + 1 = 1001
		candidates[1] = pow(10, N) + 1;

		long long nPrefix = stoll(n.substr(0, (N + 1) / 2));

		// case 3. directly copy prefix half to suffix half
		// e.g. 12345 -> 12321
		string sPrefix = to_string(nPrefix);
		candidates[2] = stoll(sPrefix + string(sPrefix.rbegin() + (N % 2), sPrefix.rend()));

		// case 4. add one to prefix half and copy to suffix half
		// e.g. 12399 -> 12421
		sPrefix = to_string(nPrefix + 1);
		candidates[3] = stoll(sPrefix + string(sPrefix.rbegin() + (N % 2), sPrefix.rend()));

		// case 5. subtract one from prefix half and copy to suffix half
		// e.g. 12321 -> 12221
		sPrefix = to_string(nPrefix - 1);
		candidates[4] = stoll(sPrefix + string(sPrefix.rbegin() + (N % 2), sPrefix.rend()));

		long long closest = -1;
		for (int i = 0; i < candidates.size(); i++) {
			if (candidates[i] == num) continue;

			if (closest == -1 ||
				(abs(candidates[i] - num) < abs(closest - num)) ||
				(abs(candidates[i] - num) == abs(closest - num) && candidates[i] < closest))
				closest = candidates[i];
		}

		return to_string(closest);
	}
};
// @lc code=end
