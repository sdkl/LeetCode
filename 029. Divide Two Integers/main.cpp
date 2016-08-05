#include<iostream>
using namespace std;


class Solution {
public:
	int divide(int dividend, int divisor) {
		if ((dividend == INT_MIN && divisor == -1) || divisor == 0)
			return INT_MAX;
			
		int d1 = dividend < 0 ? dividend : 0 - dividend;
		int d2 = divisor < 0 ? divisor : 0 - divisor;

		if (d1 > d2)
			return 0;

		bool sign = (dividend >= 0 && divisor >= 0) || (dividend <= 0 && divisor <= 0);
		int result = 1,dd2 = d2;
		while (((dd2 << 1) < dd2) && ((dd2 << 1) >= d1))
		{
			dd2 = dd2 << 1;
			result = result << 1;
		}

		result += divide(d1 - dd2, d2);
		return sign ? result : 0 - result;
	}
};

int main()
{
	Solution s;
	cout << s.divide(INT_MIN, INT_MAX) << endl;


	getchar();
	return 0;
}