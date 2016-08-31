#include<iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double result = 1, i = 0, step = 1,mul = x;
		int pn = n > 0 ? -n : n;
		while (i > pn)
		{
			if (i < INT_MIN + step || i - step < pn)
			{
				mul = x;
				step = 1;
			}
			result *= mul;
			i -= step;
			mul *= mul;
			step *= 2;
		}
		return n >= 0 ? result : 1 / result;
	}
};

int main()
{
	Solution s;
	cout << s.myPow(2, 10) << endl;
	cout << s.myPow(2, INT_MIN) << endl;

	getchar();
	return 0;
}