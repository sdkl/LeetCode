#include<iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int num = 0;

		while ((n /= 5) > 0)
			num += n;

		return num;
	}
};

int main()
{
	Solution s;
	cout << s.trailingZeroes(200) << endl;

	getchar();
	return 0;
}