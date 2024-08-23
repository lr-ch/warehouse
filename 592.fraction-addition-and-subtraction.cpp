/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start
class Solution {
	class Fraction {
		int numerator = 0, denominator = 1;
	public:
		Fraction() {}
		Fraction(int n, int d) : numerator(n), denominator(d) {}
		Fraction& operator+(const auto& rhs) {
			int LCM = lcm(denominator, rhs.denominator);
			numerator = numerator * (LCM / denominator) + rhs.numerator * (LCM / rhs.denominator);
			denominator = LCM;
			return *this;
		}

		string reduce() {
			int GCD = gcd(numerator, denominator);
			numerator /= GCD, denominator /= GCD;
			return to_string(numerator) + '/' + to_string(denominator);
		}
	};

public:
	string fractionAddition(string expression) {
		expression += '+';	// for convinently parsing

		Fraction res;
		bool isNegative = (expression[0] == '-'), parsingNumerator = true;
		int numerator = 0, denominator = 0, i = (isNegative ? 1 : 0);

		while (i < expression.size()) {
			switch (expression[i]) {
				case '/' :
					parsingNumerator = !parsingNumerator;
					break;

				case '+' :
				case '-' :
					if (isNegative) numerator *= -1;
					res = res + Fraction(numerator, denominator);

					// reset states
					isNegative = (expression[i] == '-');
					parsingNumerator = true;
					numerator = 0;
					denominator = 0;
					break;

				default :
					if (parsingNumerator)
						numerator = numerator * 10 + (expression[i] - '0');
					else
						denominator = denominator * 10 + (expression[i] - '0');
					break;
			}
			i++;
		}
		return res.reduce();
	}
};
// @lc code=end
