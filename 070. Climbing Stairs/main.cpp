#include<iostream>
using namespace std;

class Solution {
public:
	int combination(int m, int n) {
		if (m > n)
			return combination(n, m);

		double result = 1;
		for (int i = 0; i < m; i++)
		{
			result = result * (n - m + i + 1) / (i + 1);
		}
		return result;
	}

	int climbStairs(int n) {
		int result = 0, i = 0;

		while (i <= n)
		{
			result += combination(i, n);
			i++;
			n--;
		}

		return result;
	}
};

int main()
{
	Solution s;
	cout << s.climbStairs(90) << endl;

	getchar();
	return 0;
}