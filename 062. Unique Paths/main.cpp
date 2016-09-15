#include<iostream>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		m--;
		n--;
		int oneWay = m < n ? m : n, allStep = m + n;
		double result = 1;
		for (int i = 0; i < oneWay; i++)
		{
			result = result * (allStep - oneWay + i + 1) / (i + 1);
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.uniquePaths(51, 9) << endl;

	getchar();
	return 0;
}